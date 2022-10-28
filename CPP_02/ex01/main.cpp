#include "Fixed.hpp"

void	subjectTest(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

int main(void) 
{
	subjectTest();

	// Fixed a;
	// Fixed b(-20);
	// Fixed c(12345.54351f);

	// std::cout << "b is " << b << std::endl;

	// std::cout << "c is " << c << std::endl;
	// std::cout << "c.toInt() " << c.toInt() << std::endl;

	// a = b;
	// std::cout << "a is " << a << std::endl;
	// a = Fixed(c);
	// std::cout << "a is " << a << std::endl;

	// Fixed d(a);
	// std::cout << "d is " << d << std::endl;
	return 0;
}
