/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:50:06 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/10 13:37:24 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string tar);
        ShrubberyCreationForm(const ShrubberyCreationForm &oldobj);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &oldobj);
        void    execute(Bureaucrat const & executor) const;
        ~ShrubberyCreationForm();
};

#endif