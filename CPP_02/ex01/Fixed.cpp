#include "Fixed.hpp"

const int Fixed::m_fractBits = 8;

//Contructor
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	m_fixedPointVal = 0;
}

//Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

//Copy contructor
Fixed::Fixed(const Fixed &copyFixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copyFixed;
}

//Copy assignment operator
Fixed &Fixed::operator=(const Fixed &copyFixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copyFixed)
		m_fixedPointVal = copyFixed.getRawBits();
	return (*this);
}

Fixed::Fixed(int const raw)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits((int)(raw * (1 << m_fractBits)));
}

Fixed::Fixed(const float fRaw)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(fRaw * (1 << m_fractBits)));
}

float Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (float)(1 << m_fractBits));
}

int Fixed::toInt(void) const
{
	return (getRawBits() / (int)(1 << m_fractBits));
}

void Fixed::setRawBits(int const raw)
{
	m_fixedPointVal = raw;
}

int Fixed::getRawBits(void) const
{
	return (m_fixedPointVal);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}
