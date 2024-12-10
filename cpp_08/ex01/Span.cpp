/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:49:22 by abkhairi          #+#    #+#             */
/*   Updated: 2024/10/15 13:20:08 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {
	
}

void Span::addNumber(int nbr)
{
	if (vec.size() == this->N)
		throw "error ";
	vec.push_back(nbr);
	std::sort(vec.begin(), vec.end());
}

int	Span::shortestSpan(){
	int min_distance;
	int tmp_min;
	int flag = 0;

	if (vec.size() < 2)
		throw ("error size");
	else
	{
		
		for (std::vector<int>::iterator it1 = vec.begin(); it1 != vec.end(); it1++)
		{
			for (std::vector<int>::iterator it2 = it1 + 1; it2 != vec.end(); it2++)
			{
				tmp_min = (*it2) - (*it1);
				if (flag == 0)
				{
					min_distance = tmp_min;
					flag = 1;
				}
				if (min_distance <= tmp_min)
					min_distance = min_distance;
				else
					min_distance = tmp_min;
				// std::cout << "min = " << min_distance << std::endl;
			}	
		}
	}
	return (min_distance);
}

int	Span::longestSpan(){
	int max_distance;
	int tmp_max;
	int flag = 0;

	if (vec.size() < 2)
		throw ("error size");
	else
	{
		for (std::vector<int>::iterator it1 = vec.begin(); it1 != vec.end(); it1++)
		{
			for (std::vector<int>::iterator it2 = it1 + 1; it2 != vec.end(); it2++)
			{
				tmp_max = (*it2) - (*it1);
				if (flag == 0)
				{
					max_distance = tmp_max;
					flag = 1;
				}
				if (max_distance <= tmp_max)
					max_distance = tmp_max;
				else
					max_distance = max_distance;
			}	
		}
	}
	// resume max_distance =  end - begin; 
	return (max_distance);
}

void Span::display()
{
	for(std::vector<int>::iterator it = vec.begin();it != vec.end(); it++)
	{
		std::cout << "value = " << (*it) << std::endl; 
	}
}

Span& Span::operator=(const Span &ob)
{
	if (this == &ob)
		return (*this);
	this->vec.assign(ob.vec.size(), 0);
	std::copy(ob.vec.begin(), ob.vec.end(), this->vec.begin());
	return (*this);
}

Span::Span(const Span &oldobj) {
    *this = oldobj;
}

Span::Span(unsigned int n) {
	this->N = n;
	vec.reserve(N);
}

Span::~Span(){
  
}
