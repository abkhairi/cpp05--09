/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:16:57 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/18 14:23:40 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try
	{
		std::cout << "\n\033[1;32m--------shure---------------\033[0m\n";
		Bureaucrat	bur("bureau_shure", 3);
		ShrubberyCreationForm form_shur("target_shure");
		bur.signForm(&form_shur);
		form_shur.execute(bur);
		bur.executeForm(form_shur);

		std::cout << "\n\033[1;32m---------press--------------\033[0m\n";
		Bureaucrat	bur2("bureau_presi", 2);
		PresidentialPardonForm form_pres("target_president");
		bur2.signForm(&form_pres);
		form_pres.execute(bur2);

		std::cout << "\n\033[1;32m---------robo--------------\033[0m\n";
		Bureaucrat	bur3("bureau_robo", 2);
		RobotomyRequestForm form_robo("target_robo");
		bur3.signForm(&form_robo);
		form_robo.execute(bur3);
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cerr << e.what() <<std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}