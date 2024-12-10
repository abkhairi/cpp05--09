/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:17:34 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/18 14:18:01 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default")
{
    this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
    if (_grade < 1)
        throw(GradeTooHighException());
    if (_grade > 150)
        throw(GradeTooLowException());
    grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &oldobj)
{
   *this = oldobj;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj)
    {
        const_cast<std::string&>(this->name) = obj.getName(); // const_cast used to add or remove the const
        this->grade = obj.getGrade();
    }
    return *this;
}

std::string Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

void Bureaucrat::increment()
{
    if (grade - 1 <= 0)
        throw(GradeTooHighException());
    grade--;
}
void Bureaucrat::decrement()
{
    if (grade + 1 > 150)
        throw(GradeTooLowException()); 
    grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "the grade is too hight";
}
//throw(): which means this function is not supposed to throw any exceptions.

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "the grade is too low";
}

void Bureaucrat::signForm(AForm *f)
{
    f->beSigned(*this);
    if (f->get_status_s() == true)
        std::cout << getName() <<" signed " << f->get_name_form() << std::endl;
    else
        std::cout << getName() <<" couldn t sign " << f->get_name_form() << " because grade wasn't high enough\n";
}


void Bureaucrat::executeForm(AForm const & form){
    try
	{
		form.execute(*this);
        std::cout << this->getName() << " executed " << form.get_name_form() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " cannot execute " << form.get_name_form() << " because: " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}

Bureaucrat::~Bureaucrat()
{
}
