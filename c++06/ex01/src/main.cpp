/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/Serializer.hpp"

int main()
{
    // Crear un objeto Data
    Data* originalData = new Data;
    originalData->value = 42;

    // Utilizar serialize en la dirección del objeto Data
    uintptr_t serializedValue = Serializer::serialize(originalData);

    // Pasar el valor serializado a deserialize
    Data* deserializedData = Serializer::deserialize(serializedValue);

    // Asegurar que el valor de retorno de deserialize sea igual al puntero original
    if (originalData == deserializedData)
    {
        std::cout << "Success!" << std::endl;
        std::cout << "Original value: " << originalData->value << std::endl;
    }
    else
        std::cout << "Fail!" << std::endl;

    // Liberar la memoria asignada dinámicamente
    delete originalData;

    return 0;
}