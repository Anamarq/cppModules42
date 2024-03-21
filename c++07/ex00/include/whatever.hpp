
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#pragma once
#ifndef WHATEVER_HPP
#define WHATEVER_HPP


#include <iostream>

//T es un tipo de dato genérico, lo que significa que puede ser cualquier tipo de dato válido en C++
//swap: Swaps the values of two given arguments. Does not return anything.
template <typename T> //Declaracion de plantilla
void  swap(T& a, T& b) {
    T c = a;
    a = b;
    b = c;
}
//min: Compares the two values passed in its arguments and returns the smallest
//one. If the two of them are equal, then it returns the second one.
template <typename T>
T min(T a, T b) {
    //return (b < a) ? b : a;
    if (b < a)
        return b;
    return a;
}

//max: Compares the two values passed in its arguments and returns the greatest one.
//If the two of them are equal, then it returns the second one.
template <typename T>
T max(T a, T b) {
    //return (a < b) ? b : a;
    if (b > a)
        return b;
    return a;
}

#endif