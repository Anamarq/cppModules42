/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), target("") {}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target){}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target){}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
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

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!getIsSigned() || executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	else
		std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}