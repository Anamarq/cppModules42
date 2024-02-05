/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/Form.hpp"

Form::Form() : name(""), isSigned(false), requiredSignGrade(0), requiredExecuteGrade(0) {}
Form::Form(const std::string& _name, bool _isSigned, int _signGrade, int _executeGrade)
	: name(_name), isSigned(_isSigned), requiredSignGrade(_signGrade), requiredExecuteGrade(_executeGrade)
{
	if (_signGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150)
		throw GradeTooLowException();
}
//Al haber miembros const no se puede inicializar como *this = other, se tiene que hacer así, 
//por eso hay que inicializar estas constantes en la lista de inicialización del constructor de copia
Form::Form(const Form& other)
	: name(other.name),
	isSigned(other.isSigned),
	requiredSignGrade(other.requiredSignGrade),
	requiredExecuteGrade(other.requiredExecuteGrade)
{
}
Form::~Form(){}
Form& Form::operator=(const Form& other)
{
	if (this == &other)
		return *this;
	isSigned = other.getIsSigned();
	return *this;
}

std::string Form::getName() const
{
	return name;
}
bool Form::getIsSigned() const
{
	return isSigned;
}
int Form::getSignGrade() const
{
	return requiredSignGrade;
}
int Form::getExecuteGrade() const
{
	return requiredExecuteGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= getSignGrade())
		isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& ofs, Form const& object)
{
	ofs << object.getName() << ", form grade to sign: " << object.getSignGrade()
		<< ", form grade to execute: " << object.getExecuteGrade();
	return ofs;
}