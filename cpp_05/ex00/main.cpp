/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:17:25 by abkhairi          #+#    #+#             */
/*   Updated: 2024/12/10 11:41:56 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
	try
	{
		try
		{
			Bureaucrat test("test", 10);	
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		Bureaucrat a("a", 15);
		Bureaucrat b("b", 1);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		a.decrement();
		b.increment();

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << "Finn\n";

	return (0);
}
