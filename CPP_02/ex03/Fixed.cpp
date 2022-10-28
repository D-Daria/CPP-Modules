#include "Fixed.hpp"

const int Fixed::m_fractBits = 8;

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

//Contructor
Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	m_fixedPointVal = 0;
}

//Destructor
Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

//Copy contructor
Fixed::Fixed(const Fixed &copyFixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copyFixed;
}

//Copy assignment operator
Fixed &Fixed::operator=(const Fixed &copyFixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	m_fixedPointVal = copyFixed.getRawBits();
	return (*this);
}

Fixed::Fixed(const int raw)
{
	// std::cout << "Int constructor called" << std::endl;
	m_fixedPointVal = raw;
	setRawBits((int)(raw * (1 << m_fractBits)));
}

Fixed::Fixed(const float fRaw)
{
	// std::cout << "Float constructor called " << fRaw << std::endl;
	m_fixedPointVal = fRaw;
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

//Overloading comparison operators
bool Fixed::operator>(const Fixed &fix)
{
	return (this->toFloat() > fix.toFloat());
}

bool Fixed::operator<(const Fixed &fix)
{
	return (this->toFloat() < fix.toFloat());
}

bool Fixed::operator>=(const Fixed &fix)
{
	return (this->toFloat() >= fix.toFloat());
}

bool Fixed::operator<=(const Fixed &fix)
{
	return (this->toFloat() <= fix.toFloat());
}

bool Fixed::operator==(const Fixed &fix)
{
	return (this->toFloat() == fix.toFloat());
}

bool Fixed::operator!=(const Fixed &fix)
{
	return (this->toFloat() != fix.toFloat());
}

//---Overloading arithmetic operators---//
float Fixed::operator+(const Fixed &fix)
{
	return (this->toFloat() + fix.toFloat());
}

float Fixed::operator-(const Fixed &fix)
{
	return (this->toFloat() - fix.toFloat());
}

float Fixed::operator*(const Fixed &fix)
{
	return (this->toFloat() * fix.toFloat());
}

float Fixed::operator/(const Fixed &fix)
{
	return (this->toFloat() / fix.toFloat());
}

//---Overloading increment/decrement---//
//preincrement
Fixed &Fixed::operator++()
{
	++m_fixedPointVal;
	return (*this);
}

//postincrement
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

//predecrement
Fixed &Fixed::operator--()
{
	--m_fixedPointVal;
	return (*this);
}

//postdecrement
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--(); //pre-decrement this instance
	return (tmp);
}

//public overloaded functions
Fixed &Fixed::min(Fixed &fix1, Fixed &fix2)
{
	return (fix1.toFloat() < fix2.toFloat() ? fix1 : fix2);
}

const Fixed &Fixed::min(Fixed const &fix1, Fixed const &fix2)
{
	return (fix1.toFloat() < fix2.toFloat() ? fix1 : fix2);
}

Fixed &Fixed::max(Fixed &fix1, Fixed &fix2)
{
	return (fix1.toFloat() > fix2.toFloat() ? fix1 : fix2);
}

const Fixed &Fixed::max(Fixed const &fix1, Fixed const &fix2)
{
	return (fix1.toFloat() > fix2.toFloat() ? fix1 : fix2);
}
