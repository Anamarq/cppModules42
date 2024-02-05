/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(150) {}
Bureaucrat::Bureaucrat(const std::string& _name, int _grade) : name(_name)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();

	grade = _grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
}
Bureaucrat::~Bureaucrat(){}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return *this;
	grade = other.grade;
	return *this;
}
std::string Bureaucrat::getName() const
{
	return name;
}
int Bureaucrat::getGrade() const
{
	return grade;
}
void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	++grade;
}
void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	--grade; 
}

//Firma si puede
void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form)
{
	//<bureaucrat> executed <form>
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << getName() << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& ofs, Bureaucrat const& object)
{
	//<name>, bureaucrat grade <grade>.
	ofs << object.getName() << ", bureaucrat grade " << object.getGrade();
	return ofs;
}