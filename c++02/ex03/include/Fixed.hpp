#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed{
public:
	Fixed();
	Fixed(const int _valor);
	Fixed(const float _valor);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	//Operadores de comparación
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	//operadores aritméticos
	Fixed operator*(const Fixed& other) const;
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	//operadores incremento decremento
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	//min/max
	static const Fixed& min(const Fixed& n1, const Fixed& n2);
	static Fixed& min(Fixed& n1, Fixed& n2);
	static const Fixed& max(const Fixed& n1, const Fixed& n2);
	static Fixed& max(Fixed& n1, Fixed& n2);

	friend std::ostream& operator<<(std::ostream& ofs, Fixed const& object);
	
	~Fixed();
	void setRawBits(int const raw);
	int getRawBits(void) const;
	float toFloat(void) const;
	int toInt(void) const;
private:
	int valor;
	static const int fracBits = 8;
};
#endif