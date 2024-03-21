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

#include "../include/Iter.hpp"

int main()
{
    // Test with an array of integers
    int intArray[] = { 1, 2, 3, 4, 5, 5 };
    std::cout << "Testing with int array: ";
    iter(intArray, 6, function<int>);
    std::cout << std::endl;

    // Test with an array of doubles
    double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    std::cout << "Testing with double array: ";
    iter(doubleArray, 5, function<double>);
    std::cout << std::endl;

    // Test with an array of characters
    char charArray[] = { 'a', 'b', 'c', 'd', 'e' };
    std::cout << "Testing with char array: ";
    iter(charArray, 5, function<char>);
    std::cout << std::endl;
}