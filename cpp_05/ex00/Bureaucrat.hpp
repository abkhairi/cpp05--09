/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:17:15 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/18 13:33:10 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>


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
        Bureaucrat& operator=(const Bureaucrat &obj); //assignment operator 

    // getter methodes
        int  getGrade() const;
        std::string getName()const;
    
    //methods to modify grade
        void increment();
        void decrement();
    
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