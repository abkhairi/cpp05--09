/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:38:17 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/18 13:53:31 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
            const std::string   name_f;
            bool                sign_or_no;
            const int           grad_for_sign;
            const int           grad_for_exc_sign;
    public :
        Form();
        Form(std::string n, bool s, int grad_s, int grad_e);
        Form(const Form &o);
        Form& operator=(const Form &o); //assignment methode 
        ~Form();
    
        std::string get_name_form() const;
        bool        get_status_s() const;
        int         get_grad_sign() const;
        int         get_grad_exec() const;
        void        beSigned(Bureaucrat &bureauct);
        
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

std::ostream& operator<<(std::ostream& out, const Form& obj);
#endif