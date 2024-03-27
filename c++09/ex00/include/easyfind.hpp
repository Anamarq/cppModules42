/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2024/02/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <iostream>
#include <algorithm>


//this function has to find the first occurrence of the second parameter in the first parameter
template <typename T> //Declaracion de plantilla
int  easyfind(const T& container, int i)
{
	//Si encuentra el valor, devuelve un iterador que apunta a la primera ocurrencia de ese valor dentro del rango.
	//Si no se encuentra el valor, devuelve el iterador de final del rango (end())
	//auto iter... (NO en cpp98)
	typename T::const_iterator iter = std::find(container.begin(), container.end(), i);
	if (iter == container.end())
		throw std::runtime_error("NOOOO :^[ value is not in the container");
	else
		return static_cast<unsigned int>(std::distance(container.begin(), iter));
}


#endif