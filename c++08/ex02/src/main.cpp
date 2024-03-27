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
#include "../include/MutantStack.hpp"


int main() {
    MutantStack<int> mutantStack;

    // Push some elements into the stack
    mutantStack.push(1);
    mutantStack.push(2);
    mutantStack.push(3);
    mutantStack.push(4);
    mutantStack.push(5);

    // Iterate over the stack using iterators
    std::cout << "Iterating over MutantStack:" << std::endl;
    for (const auto& elem : mutantStack) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
