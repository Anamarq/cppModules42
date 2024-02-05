#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
class Fixed{
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	void setRawBits(int const raw);
	int getRawBits(void) const;
private:
	int valor;
	static const int bitsFrac = 8;
};

#endif