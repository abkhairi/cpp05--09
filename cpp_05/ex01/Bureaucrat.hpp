/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:17:41 by abkhairi          #+#    #+#             */
/*   Updated: 2024/06/27 17:08:47 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int   grade;
    public:
    //constructor
        Bureaucrat();
        Bureaucrat(std::string _name, int _grade);
        Bureaucrat(const Bureaucrat &oldobj);

    //assignment operator 
        Bureaucrat& operator=(const Bureaucrat &obj);

    // getter methodes
        int  getGrade() const;
        std::string getName()const;
    
    //methods to modify grade
        void increment();
        void decrement();

        void signForm(Form f);
    //deconstructor
        ~Bureaucrat();
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public  std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif