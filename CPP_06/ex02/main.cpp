#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define RESET   "\033[0m"
#define BLUE    "\033[34m"

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <exception>

void print_type(int type)
{
	std::string types[] = {"A", "B", "C"};

	std::cout << BLUE << types[type] << RESET << std::endl;
}

Base * generate(void)
{
	int val = (std::rand() % 1000 + 1);
	switch (val % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
	}
	return (new C());
}

void identify(Base* p)
{
	std::cout << "Actual type of object pointer is ";
	if (dynamic_cast<A *>(p))
		print_type(0);
	else if (dynamic_cast<B *>(p))
		print_type(1);
	else if (dynamic_cast<C *>(p))
		print_type(2);
	else
		std::cout << "NULL" << std::endl;
}

void identify(Base& p)
{
	std::cout << "Actual type of object reference is ";
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		print_type(0);
	}
	catch(const std::bad_cast& e)
	{}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		print_type(1);
	}
	catch(const std::bad_cast& e)
	{}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		print_type(2);
	}
	catch(const std::bad_cast& e)
	{}
}

int main(void)
{
	srand(time(0));

	Base *base = generate();

	std::cout << "---------------------" << std::endl;
	std::cout << "---identify(*base)---" << std::endl;
	std::cout << "---------------------" << std::endl;
	identify(base);

	std::cout << "---------------------" << std::endl;
	std::cout << "---identify(&base)---" << std::endl;
	std::cout << "---------------------" << std::endl;
	identify(*base);

	delete base;
	return (1);
}
