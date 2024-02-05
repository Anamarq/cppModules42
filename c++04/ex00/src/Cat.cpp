/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}
void Cat::makeSound() const
{
	std::cout << "Adorable kitty meow meow" << std::endl;
}
//Cat::Cat(const Cat& other) : Animal(other)
//{
//	*this = other;
//}
//Cat& Cat::operator=(const Cat& other)
//{
//	std::cout << "Cat assignation operator called" << std::endl;
//	if (this == &other)
//		return *this;
//	type = other.type;
//	return *this;
//}