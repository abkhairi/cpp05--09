/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:50:03 by abkhairi          #+#    #+#             */
/*   Updated: 2024/07/10 13:42:30 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", false,145, 137) 
{
	this->target = "Default";
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string tar) : AForm("shrubbery", false, 145, 137){
    this->target = tar;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &oldobj) : AForm(oldobj)
{
    this->target = oldobj.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &oldobj){
    if (this != &oldobj)
    {
        this->target = oldobj.target;
        AForm::operator=(oldobj);
    }
    return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
    
    if ( executor.getGrade() <= this->get_grad_exec())
    {
        std::ofstream outfile((executor.getName() + "_shrubbery").c_str());
        if (!outfile)
            std::cerr << "Unable to open file for writing "<< std::endl;
        else {
            outfile << "       _-_\n";
            outfile << "    /~~   ~~\\\n";
            outfile << " /~~         ~~\\\n";
            outfile << "{               }\n";
            outfile << " \\  _-     -_  /\n";
            outfile << "   ~  \\ //  ~\n";
            outfile << "_- -   | | _- _\n";
            outfile << "  _ -  | |   -_\n";
            outfile << "      // \\\n";
            outfile.close();
        }
    }
    else
        throw(GradeTooLowException());
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    
}