/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
// Definition of the static helper method outside the class
bool ScalarConverter::convertToChar(const std::string& str, char& charValue)
{
    //si pones 'a'
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'' && std::isprint(str[1]) && !std::isdigit(str[1]))
    {
        charValue = str[1];
        return true;
    }
    //si pones a
    if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
    {
        charValue = str[0];
        return true;
    }
    return false;
}

 // Static method to convert the string representation of a C++ literal to various scalar types
void ScalarConverter::convert(const std::string& str) {
    char charValue;
    int intValue;
    float floatValue;
    double doubleValue;

    if (str == "-inff" || str == "+inff" || str == "nanf")
    {
        std::cerr << "char: impossible" << std::endl;
        std::cerr << "int: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
        return;
    }
    else if (str == "-inf" || str == "+inf" || str == "nan")
    {
        std::cerr << "char: impossible" << std::endl;
        std::cerr << "int: impossible" << std::endl;
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << str << std::endl;
        return;
    }

    // Attempt to convert to char
    if (convertToChar(str, charValue)) {
        std::cout << "char: " << charValue << std::endl;
        std::cout << "int: " << static_cast<int>(charValue) << std::endl;
        std::cout << "float: " << static_cast<float>(charValue) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(charValue) << ".0" << std::endl;
        return;
    }
    else
    {
        std::cerr << "char: Non displayable." << std::endl;
    }

    
    // Attempt to convert to int
    //print if conversion is succefull
    std::istringstream intStream(str);
    intStream >> intValue;
    if (!intStream.fail())
    {
       // std::cout << "char: '*'" << std::endl;
        std::cout << "int: " << intValue << std::endl;
        
    }
    else {
        std::cerr << "int: impossible" << std::endl;
    }

    // Attempt to convert to float
    std::istringstream floatStream(str);
    floatStream >> floatValue;
    if (!floatStream.fail())
    {
        if (floatValue - static_cast<int>(floatValue) == 0)
        {
            std::cout << "float: " << intValue << ".0f" << std::endl;
            std::cout << "double: " << intValue << ".0" << std::endl;
            return;
        }
        std::cout << "float: " << floatValue << "f" << std::endl;
    }
    else
    {
        std::cerr << "float: impossible" << std::endl;
    }


    // Attempt to convert to double
    std::istringstream doubleStream(str);
    doubleStream >> doubleValue;
    if (!doubleStream.fail()) {
        std::cout << "double: " << doubleValue << std::endl;
    }
    else {
        std::cerr << "double: impossible" << std::endl;
    }

}