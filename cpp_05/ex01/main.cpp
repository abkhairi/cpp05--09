/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:16:57 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/18 13:58:10 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "--------------EX1------------"<< std::endl;
	try
	{
		Bureaucrat	bur("Jax", 5);
		Form form1("FORM1", false, 15, 17);
		
        std::cout << form1;
		std::cout << std::endl;
        bur.signForm(form1);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() <<std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr <<e.what() << std::endl;
	}

	
	std::cout << "\n-------------EX2-------------"<< std::endl;
	try
	{
		Bureaucrat	bur2("abdo", 51);
		Form form2("FORM2", false, 15, 17);
		
        std::cout << form2;
		std::cout << std::endl;
        bur2.signForm(form2);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() <<std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}