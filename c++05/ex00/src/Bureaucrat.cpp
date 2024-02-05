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


std::ostream& operator<<(std::ostream& ofs, Bureaucrat const& object)
{
	//<name>, bureaucrat grade <grade>.
	ofs << object.getName() << ", bureaucrat grade " << object.getGrade();
	return ofs;
}