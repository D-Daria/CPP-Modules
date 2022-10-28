#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	// Fixed a;
	// a.setRawBits(10);
	// std::cout << "a:" << a.getRawBits() << std::endl;

	// Fixed b(a);
	// std::cout << "b:" << b.getRawBits() << std::endl;

	// Fixed c;
	// c = a;
	// std::cout << "c:" << c.getRawBits() << std::endl;
	return 0;
}
