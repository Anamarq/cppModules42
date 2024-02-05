#include "../include/Fixed.hpp"

int potBase2(int exp)
{
	int res = 1;
	for (int i = 0; i < exp; i++) {
		res *= 2;
	}
	return res;
}

Fixed::Fixed() : valor(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int _valor)
{
	std::cout << "Int constructor called" << std::endl;
	valor = _valor * potBase2(fracBits);
}
Fixed::Fixed(const float _valor)
{
	std::cout << "Float constructor called" << std::endl;
	valor = roundf(_valor * potBase2(fracBits));
}
Fixed::Fixed(const Fixed& other) : valor(other.valor)
{
	std::cout << "Copy constructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &other) {
		return *this;
	}
	valor = other.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& ofs, Fixed const& object) {
	ofs << object.toFloat();
	return ofs;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

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
