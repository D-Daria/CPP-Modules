#include "whatever.hpp"

#include <iostream>
#include <string>

void	subjectTest(void)
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int main( void ) {

	std::cout << "-------------" << std::endl;
	std::cout << "---SUBJECT---" << std::endl;
	std::cout << "-------------" << std::endl;
	subjectTest();
	std::cout << std::endl;

	{
		float a = 42.42f;
		float b = 21.21f;
		std::cout << "a = " << a << ", b = " << b << std::endl;

		swap(a, b);
		std::cout << "swap(a, b)" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;

		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
	}
	return 0;
}
