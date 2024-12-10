/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:38:14 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/18 13:54:26 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name_f("defualt"), sign_or_no(false), grad_for_sign(150), grad_for_exc_sign(150)
{
    
}

Form::Form(std::string n, bool s, int grad_s, int grad_e) : name_f(n), sign_or_no(s), grad_for_sign(grad_s), \
    grad_for_exc_sign(grad_e) 
{
    if (grad_s < 1 || grad_e < 1)
        throw(GradeTooHighException()); 
    if (grad_s > 150 || grad_e > 150)
        throw(GradeTooLowException()); 
}

Form &Form::operator=(const Form &o)
{
    if (this == &o)
		return (*this);
	this->sign_or_no = o.sign_or_no;
	return (*this);
}

Form::Form(const Form &o): name_f(o.name_f), grad_for_sign(o.grad_for_sign), grad_for_exc_sign(o.grad_for_exc_sign)
{
    sign_or_no = o.sign_or_no;
}

std::string Form::get_name_form() const
{
    return (name_f);
}
bool Form::get_status_s() const
{
    return (sign_or_no);
}
int Form::get_grad_sign() const
{
    return (grad_for_sign);
}
int Form::get_grad_exec() const
{
    return (grad_for_exc_sign);   
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "the grade hight";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "the grade low";
}

void        Form::beSigned(Bureaucrat &bureauct)
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

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
    out << "name : " << obj.get_name_form() << std::endl;
    out << "signed : " << std::boolalpha << obj.get_status_s() << std::endl;
    out << "grade of sign : " << obj.get_grad_sign() << std::endl;
    out << "grade of execute : " << obj.get_grad_exec() << std::endl;
    return out;
}

Form::~Form()
{
}