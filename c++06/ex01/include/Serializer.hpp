/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SERIALIZER_HPP
#define	SERIALIZER_HPP

#include <iostream>
//#include <cstdint>
#include <stdint.h>

struct Data
{
    int value;
};

class Serializer
{
private:
    Serializer();  // Constructor privado para evitar la instanciación
    Serializer(const Serializer& other);
    ~Serializer();
    Serializer& operator=(const Serializer& other);

public:
    static uintptr_t serialize(Data* ptr);

    static Data* deserialize(uintptr_t raw);
};

#endif
