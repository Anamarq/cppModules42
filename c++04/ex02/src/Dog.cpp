/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/Dog.hpp"
Dog::Dog() : Animal("Dog")
{
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}
Dog::Dog(const Dog& other) : Animal(other)
{
	*this = other;
}
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	type = other.type;
	brain = new Brain(*other.brain);
	return *this;
}
void Dog::makeSound() const
{
	std::cout << "Dog guau guau" << std::endl;
}