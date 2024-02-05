#include "../include/Point.hpp"
int main(void) {
	Point p(3, 1.1f);
	//Puntos triángulo
	Point a(0, 0);
	Point b(0, 3);
	Point c(5, 0);
	if (bsp(a, b, c, p))
		std::cout << "Dentro" << std::endl;
	else
		std::cout << "Fuera" << std::endl;
}