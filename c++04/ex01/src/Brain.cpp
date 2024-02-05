/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/Brain.hpp"
Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}
Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; ++i)
	{
		ideas[i] = other.ideas[i];
	}
	return *this;
}