/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:17:41 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/10 14:51:04 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

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

        void signForm(AForm *f);
    //deconstructor
        ~Bureaucrat();
        void   executeForm(AForm const & form); 
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