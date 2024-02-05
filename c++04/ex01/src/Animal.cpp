/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal(const std::string& _type) : type(_type)
{
	std::cout << "Animal constructor called" << std::endl;
}
Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}
Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}
void Animal::makeSound() const
{
	std::cout << "Animal makeSound called" << std::endl;
}
std::string Animal::getType() const
{
	return type;
}