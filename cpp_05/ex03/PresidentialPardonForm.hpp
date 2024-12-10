/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:46:55 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/10 13:48:00 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string tar);
        PresidentialPardonForm(const PresidentialPardonForm &oldobj);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &oldobj);
        void    execute(Bureaucrat const & executor) const;
        ~PresidentialPardonForm();
};

#endif