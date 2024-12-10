#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

class Intern {
    public :
        Intern();
        Intern(const Intern &obj);
        Intern &operator=(const Intern &obj);
        ~Intern();

        AForm *create_shur(std::string name);
        AForm *create_robo(std::string name);
        AForm *create_presid(std::string name);
        AForm *makeForm(std::string name_of_form,std::string target_of_form);
};



