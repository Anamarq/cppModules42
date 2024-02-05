#include "../include/Point.hpp"
//El valor de retorno es true si el punto est� dentro del tri�ngulo, y en caso contrario
//el valor es false.Esto quiere decir que si el punto est� en un v�rtice o el punto
//est� en un borde, el valor de retorno deber� ser false.
// Uso de coordenadas baric�ntricas. Calcular las coordenadas barioc�ntricas (u, v, w) de P 
// con respecto a los v�rtices A, B y C. Si todas son positivas el punto est� dentro.
//Los tres primeros par�metros son los v�rtices de nuestro querido tri�ngulo.
// El cuarto es el punto a evaluar.

Fixed abs(Fixed x) {
	if (x < 0)
		return (x * -1);
	return x;
}

Fixed area(Point const a, Point const b, Point const c)
{
	//�rea ABC = 0.5 * |(x_B - x_A) * (y_C - y_A) - (x_C - x_A) * (y_B - y_A)|
	Fixed m(0.5f);
	return(m * abs((b.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (b.getY() - a.getY())));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	//Calcular baric�ntricas
	Fixed areaTriangulo = area(a, b, c);
	Fixed u = area(point, b, c) / areaTriangulo;
	Fixed v = area(a, point, c) / areaTriangulo;
	Fixed w = area(a, b, point) / areaTriangulo;
	return(u > 0 && v > 0 && w > 0);
}
