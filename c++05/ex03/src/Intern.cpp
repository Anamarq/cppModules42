/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Inrtern.hpp"
Intern::Intern(){}
Intern::Intern(const Intern& other)
{
	*this = other;
}
Intern::~Intern(){}
Intern& Intern::operator=(const Intern& other)
{
    (void)other;
	return *this;
}

AForm* createRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* createShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}
AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    std::string formNames[3] = 
    { "robotomy request", 
    "shrubbery creation",
    "presidential pardon" };

    AForm* (*formCreators[3])(const std::string&) = 
    { &createRobotomyRequestForm,
      &createShrubberyCreationForm,
      &createPresidentialPardonForm };

    for (int i = 0; i < 3; ++i)
    {
        if (name == formNames[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Intern couldn't create form" << std::endl;
    return NULL;
}

//AForm* Intern::makeForm(const std::string& name, const std::string& target)
//{
//    std::map<std::string, int> switchMap;
//    switchMap["robotomy request"] = 0;
//    switchMap["shrubbery creation"] = 1;
//    switchMap["presidential pardon"] = 2;
//    if (switchMap.find(name) == switchMap.end()) {
//        std::cout << "Intern couldn't create form" << std::endl;
//        return NULL;
//    }
//    std::cout << "Intern creates " << name << std::endl;
//    switch (switchMap[name])
//    {
//    case 0:
//        return new RobotomyRequestForm(target);
//        break;
//    case 1:
//        return new ShrubberyCreationForm(target);
//        break;
//    case 2:
//        return new PresidentialPardonForm(target);
//        break;
//    default:
//        break;
//    }
//    
//    return NULL;
//}