/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:44:56 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/10 14:20:19 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string tar);
        RobotomyRequestForm(const RobotomyRequestForm &oldobj);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &oldobj);
        void    execute(Bureaucrat const & executor) const;
        ~RobotomyRequestForm();
};

#endif