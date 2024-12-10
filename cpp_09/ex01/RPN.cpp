/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:04:05 by abkhairi          #+#    #+#             */
/*   Updated: 2024/11/01 18:22:13 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &obj)
{
	*this = obj;
}

RPN& RPN::operator=(const RPN& obj)
{
    if (this != &obj)
    {
        this->my_stack = obj.my_stack;
    }
    return *this;
}



bool is_number(std::string str)
{
	size_t i = 0;

	for (i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i])) // 9 - 8
			return false;
	}
	return true;
}

bool is_operator(std::string c)
{
	return (c == "+" || c == "-" || c == "/" || c == "*");
}

int	calcule(int first_,int second_, std::string op)
{
	if(op == "+") 
		return (first_ + second_);
	if(op == "-")
		return (first_ - second_);
	if(op == "*")
		return (first_ * second_);
	if(op == "/")
	{
		if (second_ == 0)
			throw "Error";
		else
			return (first_ / second_);
	}
	else
	{
		std::cout << "Error\n";
		return 1;
	}
}

void RPN::execute(std::string str)
{
	std::stringstream ss;

	ss << str;// 2    8 +     -1 

	std::string trimed;
	while(ss >> trimed)
	{
		if (is_number(trimed) && trimed.length() == 1)
			my_stack.push(atoi(trimed.c_str()));
		else if (is_operator(trimed) == true)
		{
			if (my_stack.size() < 2)
			{
				std::cerr<<"Error\n";
				return ;
			}
			int second_;
			int first_;
			second_ = my_stack.top();
			my_stack.pop();
			first_ = my_stack.top();
			my_stack.pop();
			int res = calcule(first_, second_, trimed);
			my_stack.push(res);
		}
		else
		{
			std::cerr<<"Error\n";
			return ;
		}
	}
	if (my_stack.size() != 1)
	{
		std::cerr<<"Error\n";
		return ;
	}
	std::cout << "> Result : " << my_stack.top() << std::endl;
}

RPN::~RPN(){}

