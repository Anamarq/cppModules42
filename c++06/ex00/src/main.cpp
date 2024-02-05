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
#include "../include/ScalarConverter.hpp"

//int main() {
//    //std::cout << "char: " << static_cast<char>(23.0f) << std::endl;
//    //std::cout << "int: " << static_cast<int>(23.0f) << std::endl;
//    //std::cout << "float: " << static_cast<float>(23.0f) << ".0f" << std::endl;
//    //std::cout << "double: " << static_cast<double>(23.0f) << ".0" << std::endl;
//    ScalarConverter::convert("a");      // Example of char literal
//    ScalarConverter::convert("'a'");      // Example of char literal
//    ScalarConverter::convert("42");        // Example of int literal
//    ScalarConverter::convert("-4.2f");     // Example of float literal
//    ScalarConverter::convert("4.2");       // Example of double literal
//    ScalarConverter::convert("-inff");     // Example of float pseudo literal
//    ScalarConverter::convert("nan");       // Example of double pseudo literal
//
//    return 0;
//}
int main(int argc, char* argv[]) {
//std::cout << "char: " << static_cast<char>(23) << std::endl;
//std::cout << "int: " << static_cast<int>(23) << std::endl;
//std::cout << "float: " << static_cast<float>(23) << ".0f" << std::endl;
//std::cout << "double: " << static_cast<double>(23) << ".0" << std::endl;
    if (argc == 1) {
        std::cout << "Error: no parameters\n" << "Usage: <program> <literal>" << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);

    return 0;
}