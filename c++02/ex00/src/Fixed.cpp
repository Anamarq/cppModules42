#include "../include/Fixed.hpp"

Fixed::Fixed() : valor(0) 
{
	std::cout << "Default constructor called" << std::endl;
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
	//valor = other.valor;
	valor = other.getRawBits();
	return *this;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
	//this->valor = raw;
	valor = raw;
}
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return valor;
}
