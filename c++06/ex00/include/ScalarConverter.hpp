/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SCALARCONVERTER_HPP
#define	SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>

class ScalarConverter {
public:
    //ScalarConverter();
    //ScalarConverter(const ScalarConverter& other);
    //~ScalarConverter();
    //ScalarConverter& operator=(const ScalarConverter& other);
    // Static method to convert the string representation of a C++ literal to various scalar types
    static void convert(const std::string& literal);
private:
    ScalarConverter();
    ~ScalarConverter();
    // Helper method to convert to char
    static bool convertToChar(const std::string& literal, char& charValue);
};

#endif
