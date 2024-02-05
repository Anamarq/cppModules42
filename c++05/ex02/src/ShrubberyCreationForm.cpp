/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), target("") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target){}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return *this;
	//name = other.name;
	//isSigned = other.isSigned;
	//requiredSignGrade = other.requiredSignGrade;
	//requiredExecuteGrade = other.requiredExecuteGrade;
	AForm::operator=(other);
	target = other.target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!getIsSigned() || executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	else
	{
		//Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.
		std::string filename = target + "_shrubbery";
		std::ofstream fichero(filename.c_str());
		if (!fichero.is_open())
		{
			std::cerr << "The file could not be opened." << std::endl;
		}
		else
		{
			fichero << "    *" << std::endl;
			fichero << "   ***" << std::endl;
			fichero << "  *****" << std::endl;
			fichero << " *******" << std::endl;
			fichero << "*********" << std::endl;
			fichero << "    |" << std::endl;

			fichero.close();
		}
	}
}