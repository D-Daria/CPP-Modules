#include "Fixed.hpp"

const int Fixed::m_fractBits = 8;

//contructor
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	m_fixedPointNum = 0;
}

//destructor
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
		m_fixedPointNum = copyFixed.getRawBits();
	return (*this);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	m_fixedPointNum = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (m_fixedPointNum);
}
