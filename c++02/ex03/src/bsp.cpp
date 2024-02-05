#include "../include/Point.hpp"
//El valor de retorno es true si el punto está dentro del triángulo, y en caso contrario
//el valor es false.Esto quiere decir que si el punto está en un vértice o el punto
//está en un borde, el valor de retorno deberá ser false.
// Uso de coordenadas baricéntricas. Calcular las coordenadas bariocéntricas (u, v, w) de P 
// con respecto a los vértices A, B y C. Si todas son positivas el punto está dentro.
//Los tres primeros parámetros son los vértices de nuestro querido triángulo.
// El cuarto es el punto a evaluar.

Fixed abs(Fixed x) {
	if (x < 0)
		return (x * -1);
	return x;
}

Fixed area(Point const a, Point const b, Point const c)
{
	//Área ABC = 0.5 * |(x_B - x_A) * (y_C - y_A) - (x_C - x_A) * (y_B - y_A)|
	Fixed m(0.5f);
	return(m * abs((b.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (b.getY() - a.getY())));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	//Calcular baricéntricas
	Fixed areaTriangulo = area(a, b, c);
	Fixed u = area(point, b, c) / areaTriangulo;
	Fixed v = area(a, point, c) / areaTriangulo;
	Fixed w = area(a, b, point) / areaTriangulo;
	return(u > 0 && v > 0 && w > 0);
}
