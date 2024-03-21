
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
public:
	Array() : array(T()), sizeA(0) {}
	Array(unsigned int n) : array(new T[n]), sizeA(n)
	{
		for (unsigned int i = 0; i < sizeA; ++i)
			array[i] = T(); //Inicialize for default
	}
	~Array() {
		delete[] array;
	}
	Array(const Array& other) : array(new T[other.sizeA]), sizeA(other.sizeA)
	{
		for (unsigned int i = 0; i < sizeA; ++i)
		{
			array[i] = other.array[i];
		}
	}
	Array& operator=(const Array& other)
	{
		if (this == &other)
			return this;
		delete[] array; //Borar el array anterior
		sizeA = other.sizeA;
		array = new T[other.sizeA];
		for (unsigned int i = 0; i < sizeA; ++i)
		{
			array[i] = other.array[i];
		}
		return *this;
	}
	//Devuelve un objeto de tipo T
	T& operator[](unsigned int index)
	{
		if (index >= sizeA)
			throw OutOfBoundsException();
		return array[index];
	}
	unsigned int size() const
	{
		return sizeA;
	}

	class OutOfBoundsException : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "Index out of bounds";
		}
	};
private:
	T* array;
	unsigned int sizeA;
};


#endif