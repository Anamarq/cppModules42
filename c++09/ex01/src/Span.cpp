/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:04:53 by anamarqu          #+#    #+#             */
/*   Updated: 2024/02/06 13:04:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <cstdlib> // Para rand()
#include <ctime>   // Para time()

Span::Span() : N(0) {}
Span::~Span(){}
Span::Span(unsigned int _N): N(_N){}
Span::Span(const Span& other) : N(other.N){}
Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return *this;
	N = other.N;
	return *this;
}

void Span::addNumber(int n)
{
	if (vec.size() >= N)
		throw std::out_of_range("No cabee");
	vec.push_back(n);
	std::cout << "Anadido " << n << std::endl;
}

//numero de valores, maximo y minimo del rango
void Span::addNumbers(int n, int min, int max)
{
	// Inicializar la semilla para la generación de números aleatorios
	srand(static_cast<unsigned int>(time(NULL)));

	for (int i = 0; i < n; ++i)
	{
		if (vec.size() >= N)
			throw std::out_of_range("No cabee");
		int random = min + rand() % (max - min + 1);
		vec.push_back(random);
		std::cout << "Anadido " << random << std::endl;
	}
}

//para buscar el camino mas corto habria que hacer doble bucle y comprobar cada mumero
int Span::shortestSpan()
{
	if (vec.size() <= 1)
		throw std::runtime_error("no span can be found");
	int shortest = INT_MAX;
	for (int i = 0; i < static_cast<int>(vec.size()); ++i) {
		for (int j = i + 1; j < static_cast<int>(vec.size()); ++j) {
			int diff = std::abs(vec[j] - vec[i]);
			shortest = std::min(shortest, diff);
		}
	}
	return shortest;
}

//coger el max elemento y el minimo y restarlo, ese es el camino mas largo
int Span::longestSpan()
{
	if (vec.size() <= 1)
		throw std::runtime_error("no span can be found");
	int max = *std::max_element(vec.begin(), vec.end());
	int min = *std::min_element(vec.begin(), vec.end());
	return max - min;
}