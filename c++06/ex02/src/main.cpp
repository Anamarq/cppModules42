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

#include <cstdlib>
#include <iostream>

class Base
{
public:
	virtual ~Base();
};
Base::~Base() {}
class A : public Base {};
class B : public Base {};
class C : public Base {};

//It randomly instanciates A, B or C and returns the instance as a Base pointer.
Base* generate(void)
{
	int n = rand() % 3;
	switch (n)
	{
	case 0:
		return new C();
		break;
	case 1:
		return new A();
		break;
	case 2:
		return new B();
		break;
	default:
		return NULL;
		break;
	}
}

//It prints the actual type of the object pointed to by p : "A", "B" or "C".
void identify(Base* p)
{
	//devuelve un puntero nulo si la conversión no es válida
	if (dynamic_cast<A*>(p)) //Si se puede convertir en A
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(p)) //Si se puede convertir en B
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C*>(p)) //Si se puede convertir en C
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "Type: Unknow" << std::endl;
}

////It prints the actual type of the object pointed to by p : "A", "B" or "C".Using a pointer
////inside this function is forbidden.

void identify(Base& p)
{
	//dynamic_cast arrojará una excepción de tipo std::bad_cast si la conversión no es válida
	//esto se hace cuando se utiliza dynamic_cast con referencias, ya que arroja excepciones en lugar de devolver un puntero nulo
	try {
		dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;
	}
	catch (const std::exception& e) {}

	try {
		dynamic_cast<B&>(p);
		std::cout << "Type: B" << std::endl;
	}
	catch (const std::exception& e) {}

	try {
		dynamic_cast<C&>(p);
		std::cout << "Type: C" << std::endl;
	}
	catch (const std::exception& e) {}
	//std::cout << "Type: Unknown" << std::endl;
}

int     main(void)
{
	// Semilla para la generación de números aleatorios
	srand(static_cast<unsigned>(time(0)));
	Base* a = generate();
	identify(a);
	identify(*a); 
	std::cout << std::endl;

	Base* b = generate();
	identify(b);
	identify(*b);
	std::cout << std::endl;

	Base* c = generate();
	identify(c);
	identify(*c);
	std::cout << std::endl;

	delete a;
	delete b;
	delete c;
	return (0);
}