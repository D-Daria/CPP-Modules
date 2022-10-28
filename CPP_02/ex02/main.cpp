#include "Fixed.hpp"

void	subjectTest(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}

int main(void)
{
	subjectTest();

	/*
	Fixed a;
	Fixed c(Fixed(2.5f));
	std::cout << "c is " << c << std::endl;

	a = Fixed(2);
	std::cout << "a is " << a << std::endl;

	Fixed const b(a);
	std::cout << "b is " << b << std::endl;

	Fixed d(a * b);
	std::cout << "d is " << d << std::endl;

	d = Fixed(d * c);
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "is c > a: " << (c > a) << std::endl;
	std::cout << "is c == a: " << (c == a) << std::endl;
	std::cout << "is c != a: " << (c != a) << std::endl;

	while (c > a)
	{
		--c;
	}
	std::cout << "c is " << c << std::endl;
	std::cout << "is c == a: " << (c == a) << std::endl;
	std::cout << "is c - a: " << (c - a) << std::endl;

	d = Fixed(c + Fixed(0.5f));
	std::cout << "d is " << d << std::endl;

	Fixed m = Fixed::min(d, b);
	std::cout << "b is " << b << std::endl;
	std::cout << "Fixed::min(d, b) " << m << std::endl;
	*/
	return (0);
}
