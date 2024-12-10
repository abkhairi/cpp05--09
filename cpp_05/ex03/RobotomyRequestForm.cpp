/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:20:24 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/18 15:20:10 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("unknown", false, 72, 45) 
{
	this->target = "Default";
}


RobotomyRequestForm::RobotomyRequestForm(std::string tar) : AForm("Roboto", false, 72, 45){
    this->target = tar;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &oldobj) : AForm(oldobj)
{
    this->target = oldobj.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &oldobj){
    if (this != &oldobj)
    {
        this->target = oldobj.target;
        AForm::operator=(oldobj);
    }
    return (*this);
}


void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (this->get_status_s() == true && executor.getGrade() <= this->get_grad_exec())
    {
        // Initialisation du générateur de nombres aléatoires
        std::srand(std::time(0)); //std::time(0) retourne le nombre de secondes écoulées depuis le 1er janvier 1970
        int randvalue;
        randvalue = rand() % 2;
        std::cout << this->target << " Makes some drilling noises...\n";
        if (randvalue == 1)
            std::cout << "successfully \n";
        else
            std::cout << "failed";
    }
    else
        throw (GradeTooLowException());
}

RobotomyRequestForm::~RobotomyRequestForm(){
    
}