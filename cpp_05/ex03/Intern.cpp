#include "Intern.hpp"

Intern::Intern() {
}

AForm *Intern::create_shur(std::string name) {
    return (new ShrubberyCreationForm(name));
}

AForm *Intern::create_robo(std::string name) {
    return (new RobotomyRequestForm(name));
}

AForm *Intern::create_presid(std::string name) {
    return (new PresidentialPardonForm(name));
}

Intern::Intern(const Intern &obj){
    *this = obj;
}

Intern& Intern::operator=(const Intern &obj)
{
    (void)obj;
    return(*this);
}

AForm* Intern::makeForm(std::string name_of_form, std::string target_of_form)
{
    AForm* (Intern::*pointer[3])(std::string);
    pointer[0] = &Intern::create_shur;
    pointer[1] = &Intern::create_robo;
    pointer[2] = &Intern::create_presid;

    std::string array[3] = {"shrubbery request","robotomy request", "president request"};
    
    for (int i = 0; i < 3; i++){
        if (array[i] == name_of_form)
        {
            std::cout << "Intern create " << name_of_form <<std::endl;
            return (this->*pointer[i])(target_of_form);
        }
    }
    std::cout << "Intern failed to create form " << name_of_form <<std::endl;
    return (NULL);
}

Intern::~Intern() {
}