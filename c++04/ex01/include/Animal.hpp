/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ANIMAL_HPP
#define	ANIMAL_HPP

#include <iostream>
class Animal
{
public:
	Animal();
	Animal(const std::string& _type);
	Animal(const Animal& other);
	virtual ~Animal();
	Animal& operator=(const Animal& other);
	virtual void makeSound() const;
	std::string getType() const;
protected:
	std::string type;
};

#endif