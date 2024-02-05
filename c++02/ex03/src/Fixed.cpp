#include "../include/Fixed.hpp"

int potBase2(int exp)
{
	int res = 1;
	for (int i = 0; i < exp; i++) {
		res *= 2;
	}
	return res;
}

Fixed::Fixed() : valor(0) {}

Fixed::Fixed(const int _valor)
{
	valor = _valor * potBase2(fracBits);
}
Fixed::Fixed(const float _valor)
{
	valor = roundf(_valor * potBase2(fracBits));
}
Fixed::Fixed(const Fixed& other) : valor(other.valor) {}
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other) {
		return *this;
	}
	valor = other.getRawBits();
	return *this;
}
//Operadores de comparación
bool Fixed::operator>(const Fixed& other) const
{
	return (valor > other.getRawBits());
}
bool Fixed::operator<(const Fixed& other) const
{
	return (valor < other.getRawBits());
}
bool Fixed::operator==(const Fixed& other) const
{
	return (valor == other.getRawBits());
}
bool Fixed::operator>=(const Fixed& other) const
{
	return (valor >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed& other) const
{
	return (valor <= other.getRawBits());
}
bool Fixed::operator!=(const Fixed& other) const
{
	return (valor != other.getRawBits());
}
//operadores aritméticos
Fixed Fixed::operator*(const Fixed& other) const
{
	float res = this->toFloat() * other.toFloat();
	return Fixed(res);
}
Fixed Fixed::operator+(const Fixed& other) const
{
	float res = this->toFloat() + other.toFloat();
	return Fixed(res);
}
Fixed Fixed::operator-(const Fixed& other) const
{
	float res = this->toFloat() - other.toFloat();
	return Fixed(res);
}
Fixed Fixed::operator/(const Fixed& other) const
{
	float res = this->toFloat() / other.toFloat();
	return Fixed(res);
}
//operadores decremento/incremento
 // Sobrecarga del operador de preincremento (++obj)
//incrementa el objeto antes de utilizarlo en una expresión
Fixed& Fixed::operator++() 
{
	++valor;
	return *this;
}

// Sobrecarga del operador de postincremento (obj++)
//Devolver el objeto actual antes de incrementarlo. Para ello hago una copia e incremento el objeto antes de la modificación.
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++valor;
	return temp;
}

// Sobrecarga del operador de predecremento (--obj)
Fixed& Fixed::operator--()
{
	--valor;
	return *this;
}

// Sobrecarga del operador de postdecremento (obj--)
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--valor;
	return temp;
}
//min/max
const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2)
{
	if (n1.valor < n2.valor)
		return n1;
	return n2;
}
Fixed& Fixed::min(Fixed& n1, Fixed& n2)
{
	if (n1.valor < n2.valor)
		return n1;
	return n2;
}
const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2)
{
	if (n1.valor > n2.valor)
		return n1;
	return n2;
}
Fixed& Fixed::max(Fixed& n1, Fixed& n2)
{
	if (n1.valor > n2.valor)
		return n1;
	return n2;
}

//operador ofstream
std::ostream& operator<<(std::ostream& ofs, Fixed const& object) {
	ofs << object.toFloat();
	return ofs;
}

Fixed::~Fixed() {}

void Fixed::setRawBits(int const raw)
{
	valor = raw;
}
int Fixed::getRawBits(void) const
{
	return valor;
}
float Fixed::toFloat(void) const
{
	return (static_cast<float>(valor)) / potBase2(fracBits);
}
int Fixed::toInt(void) const
{
	return (valor / potBase2(fracBits));
}
