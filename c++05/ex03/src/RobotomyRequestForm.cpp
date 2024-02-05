/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(), target("") {}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target){}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
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

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!getIsSigned() || executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	else
	{
		//Makes some drilling noises.Then, informs that <target> has been robotomized
		//successfully 50 % of the time.Otherwise, informs that the robotomy failed.
		std::cout << "Makes some drilling noises." << std::endl;

		if (rand() % 2 == 0)
		{
			std::cout << target << " has been robotomized successfully!" << std::endl;
		}
		else
		{
			std::cout << "Robotomy failed for " << target << std::endl;
		}
	}
}