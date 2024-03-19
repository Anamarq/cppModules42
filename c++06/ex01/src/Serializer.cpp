/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/Serializer.hpp"

Serializer::Serializer() {}  // Constructor privado para evitar la instanciación

uintptr_t Serializer::serialize(Data* ptr)
{
	//e utiliza para convertir un tipo de puntero a otro tipo de puntero o para convertir un tipo de referencia a otro tipo de referencia
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

Serializer::Serializer(const Serializer& other)
{
	*this = other;
}
Serializer::~Serializer() {}
Serializer& Serializer::operator=(const Serializer& other)
{
	if (this == &other)
		return *this;
	return *this;
}