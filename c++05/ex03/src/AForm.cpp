#include "../include/AForm.hpp"

AForm::AForm() : name(""), isSigned(false), requiredSignGrade(0), requiredExecuteGrade(0) {}
AForm::AForm(const std::string& _name, int _signGrade, int _executeGrade)
	: name(_name), isSigned(false), requiredSignGrade(_signGrade), requiredExecuteGrade(_executeGrade)
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooLowException();
}
//Al haber miembros const no se puede inicializar como *this = other, se tiene que hacer así, 
//por eso hay que inicializar estas constantes en la lista de inicialización del constructor de copia
AForm::AForm(const AForm& other)
	: name(other.name),
	isSigned(other.isSigned),
	requiredSignGrade(other.requiredSignGrade),
	requiredExecuteGrade(other.requiredExecuteGrade)
{
}
AForm::~AForm(){}
AForm& AForm::operator=(const AForm& other)
{
	if (this == &other)
		return *this;
	isSigned = other.getIsSigned();
	return *this;
}

std::string AForm::getName() const
{
	return name;
}
bool AForm::getIsSigned() const
{
	return isSigned;
}
int AForm::getSignGrade() const
{
	return requiredSignGrade;
}
int AForm::getExecuteGrade() const
{
	return requiredExecuteGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= getSignGrade())
		isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& ofs, AForm const& object)
{
	ofs << object.getName() << ", form grade to sign: " << object.getSignGrade()
		<< ", form grade to execute: " << object.getExecuteGrade();
	return ofs;
}