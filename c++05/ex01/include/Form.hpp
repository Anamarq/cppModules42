/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FORM_HPP
#define	FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
public:
	Form();
	Form(const std::string& _name, bool _isSigned, int _signGrade, int _executeGrade);
	Form(const Form& other);
	~Form();
	Form& operator=(const Form& other);

	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw()
        {
            return "Invalid grade! grade too high";
        }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw()
        {
            return "Invalid grade! Grade too low";
        }
    };

private:
	const std::string name;
	bool isSigned;
	const int requiredSignGrade;
	const int requiredExecuteGrade;
};

std::ostream& operator<<(std::ostream& ofs, Form const& object);

#endif