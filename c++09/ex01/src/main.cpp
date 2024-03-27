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

#include "../include/Span.hpp"

int main()
{
    try {
        Span span(5);
        span.addNumber(2);
        span.addNumber(43);
        span.addNumber(5);
        span.addNumber(23);
        span.addNumber(1);
        std::cout << "longest span: " << span.longestSpan() << std::endl;
        std::cout << "shortest span: " << span.shortestSpan() << std::endl;

        Span span2(100);
        span2.addNumbers(100, 1, 290);
        std::cout << "longest span: " << span2.longestSpan() << std::endl;
        std::cout << "shortest span: " << span2.shortestSpan() << std::endl;

        Span span3(5);
        span3.addNumbers(5, -10, 10);
        std::cout << "longest span: " << span3.longestSpan() << std::endl;
        std::cout << "shortest span: " << span3.shortestSpan() << std::endl;
       
        span3.addNumbers(5, -10, 10);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}