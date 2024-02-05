/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
class AForm;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string& _name, int _grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& other);
	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
    void signForm(AForm& form);
    void executeForm(AForm const& form);

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
	int grade;
};
std::ostream& operator<<(std::ostream& ofs, Bureaucrat const& object);

#endif