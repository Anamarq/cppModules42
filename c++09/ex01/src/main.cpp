/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2024/02/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Not expression" << std::endl;
        return EXIT_FAILURE;
    }

    std::string expression = argv[1];
    RPN rpn(expression);
    int resultado = rpn.evaluateRPN();
    std::cout << resultado << std::endl;
}
