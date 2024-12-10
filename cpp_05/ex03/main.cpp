/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:16:57 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/18 15:16:06 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Intern a;
	AForm *ptr;
	Bureaucrat	br("none", 19);

	ptr = a.makeForm("robotomy request", "Bob");
	if (!ptr)
		return (1);
	br.signForm(ptr);
	std::cout<<*ptr<<std::endl;
	try
	{	
		ptr->execute(br);
	}
	catch(AForm::GradeTooLowException e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete ptr;
	return 0;
}



// int main()
// {
// 	Intern I1;
// 	AForm *ob;
// 	// Intern I2;
// 	// AForm *ob1;
// 	// Intern I3;
// 	// AForm *ob2;
// 	try
// 	{
// 		// ShrubberyCreationForm
// 		try
// 		{
// 			ob = I1.makeForm("shrubbery creation", "file");
// 			if (!ob)
// 				throw "";
// 			Bureaucrat bur1("b1", 136);
// 			bur1.signForm(ob);
// 			bur1.executeForm(*ob);
// 		}
// 		catch(const char *e)
// 		{
// 			std::cerr << e << '\n';
// 		}

// 		// RobotomyRequestForm
// 		// try
// 		// {
// 		// 	ob1 = I2.makeForm("robotomy request", "Robot");
// 		// 	if (!ob1)
// 		// 		throw "";
// 		// 	Bureaucrat bur2("b2", 40);
// 		// 	bur2.signForm(*ob1);
// 		// 	bur2.executeForm(*ob1);
// 		// }
// 		// catch(const char *e)
// 		// {
// 		// 	std::cerr << e << '\n';
// 		// }

// 		// // PresidentialPardonForm
// 		// try
// 		// {
// 		// 	ob2 = I3.makeForm("presidential pardon", "prisoner");
// 		// 	if (!ob2)
// 		// 		throw "";
// 		// 	Bureaucrat bur3("b3", 4);
// 		// 	bur3.signForm(*ob2);
// 		// 	bur3.executeForm(*ob2);
// 		// }
// 		// catch(const char *e)
// 		// {
// 		// 	std::cerr << e << '\n';
// 		// }
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	delete ob;
// 	// delete ob1;
// 	// delete ob2;
// 	return (0);
// }