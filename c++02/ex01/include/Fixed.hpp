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