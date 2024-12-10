/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:38:17 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/10 13:40:31 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Bureaucrat.hpp"
#include <exception>

class Bureaucrat;

class AForm
{
    private:
            const std::string   name_f;
            bool                sign_or_no;
            const int           grad_for_sign;
            const int           grad_for_exc_sign;
    public :
        AForm();//constructor
        AForm(std::string n, bool s, int grad_s, int grad_e);
        AForm(const AForm &oldobj);
        AForm& operator=(const AForm &oldobj); //assignment methode 
        ~AForm();// deconstructor
        //getter
        std::string get_name_form() const;
        // std::string get_tar() const;
        bool        get_status_s() const;
        int         get_grad_sign() const;
        int         get_grad_exec() const;
        
        void        beSigned(Bureaucrat &bureauct);
        
        virtual void execute(Bureaucrat const &executor) const = 0;
        
        class GradeTooHighException : std::exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : std::exception
        {
            public:
                const char *what() const throw();
        };
        
};


std::ostream& operator<<(std::ostream& out, const AForm& obj);
#endif