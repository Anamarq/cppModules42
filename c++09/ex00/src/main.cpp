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

#include "../include/easyfind.hpp"
#include <vector>
#include <list>
int main()
{
    try {
        int n;
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        n = easyfind(vec, 3);
        std::cout << "Yess value found!! In pos " << n << std::endl;

        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(6);
        lst.push_back(7);
        lst.push_back(8);
        lst.push_back(9);
        n = easyfind(lst, 8);
        std::cout << "Yess value found!! In pos " << n << std::endl;

        //Valor q no esta
        //No llega  aimprimir el msj
        n = easyfind(vec, 10);
        std::cout << "Yess value found!! In pos " << n << std::endl;
        std::vector<int> emptyVec;
        n = easyfind(emptyVec, 2);
        std::cout << "Yess value found!! In pos " << n << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
//int main()
//{
//	try
//	{
//		std::vector<int> vec = { 1, 2, 3, 4, 5 };
//		std::cout << "Yess value found!! In pos: " << easyfind(vec, 3) << std::endl;
//
//		std::list<int> lst = { 5, 6, 7, 8, 9 };
//		std::cout << "Yess value found!! In pos: " << easyfind(lst, 8) << std::endl;
//
//		// Prueba para un valor que no está presente en el contenedor
//		std::cout << "Yess value found!! In pos: " << easyfind(vec, 10) << std::endl; // Esto debería lanzar una excepción
//
//	}
//	catch (std::exception e)
//	{
//		std::cerr << e.what << std::endl;
//	}
//}
