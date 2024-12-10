/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:48:15 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/10 14:13:16 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("unknown", false, 25, 5) 
{
	this->target = "Default";
}


PresidentialPardonForm::PresidentialPardonForm(std::string tar) : AForm("President", false, 25, 5){
    this->target = tar;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &oldobj) : AForm(oldobj)
{
    this->target = oldobj.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &oldobj){
    if (this != &oldobj)
    {
        this->target = oldobj.target;
        AForm::operator=(oldobj);
    }
    return (*this);
}


void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (this->get_status_s() == true && executor.getGrade() <= this->get_grad_exec())
        std::cout << "the " << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    else
        throw (GradeTooLowException());
}

PresidentialPardonForm::~PresidentialPardonForm(){
    
}