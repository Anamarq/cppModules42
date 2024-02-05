/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WRONGANIMAL_HPP
#define	WRONGANIMAL_HPP

#include <iostream>
class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const std::string& _type);
	WrongAnimal(const WrongAnimal& other);
	virtual ~WrongAnimal();
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual void makeSound() const;
	std::string getType() const;
protected:
	std::string type;
};

#endif