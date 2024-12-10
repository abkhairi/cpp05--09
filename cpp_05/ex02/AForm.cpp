/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:38:14 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/10 13:40:43 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name_f("defualt"), sign_or_no(false), grad_for_sign(150), grad_for_exc_sign(150)
{
    
}

AForm::AForm(std::string n, bool s, int grad_s, int grad_e) : name_f(n), sign_or_no(s), grad_for_sign(grad_s), \
    grad_for_exc_sign(grad_e)
{
    if (grad_s < 1 || grad_e < 1)
        throw(GradeTooHighException()); 
    if (grad_s > 150 || grad_e > 150)
        throw(GradeTooLowException()); 
}

AForm::AForm(const AForm &oldobj) : grad_for_sign(150), grad_for_exc_sign(150)
{
    *this = oldobj;
}

AForm &AForm::operator=(const AForm &oldobj)
{
    if (this != &oldobj)
    {
        const_cast<std::string&>(this->name_f) = oldobj.get_name_form();
        this->sign_or_no = oldobj.get_status_s();
        const_cast<int&>(this->grad_for_sign) = oldobj.get_grad_sign();
        const_cast<int&>(this->grad_for_exc_sign) = oldobj.get_grad_exec();
    }
    return (*this);
}


std::string AForm::get_name_form() const
{
    return (name_f);
}
bool AForm::get_status_s() const
{
    return (sign_or_no);
}
int AForm::get_grad_sign() const
{
    return (grad_for_sign);
}
int AForm::get_grad_exec() const
{
    return (grad_for_exc_sign);   
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "the grade hight";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "the grade low";
}

void        AForm::beSigned(Bureaucrat &bureauct)
{
    try
    {
        if (bureauct.getGrade() <= grad_for_sign)
            sign_or_no = true;   
        else
            throw(GradeTooLowException());    
    }
    catch(const GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
    out << "name : " << obj.get_name_form() << std::endl;
    out << "signed : " << std::boolalpha << obj.get_status_s() << std::endl;
    out << "grade of sign : " << obj.get_grad_sign() << std::endl;
    out << "grade of execute : " << obj.get_grad_exec() << std::endl;
    return out;
}

AForm::~AForm()
{
}