#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address of str: ";
	std::cout << &str << std::endl << std::endl;

	std::cout << "Memory address of stringPTR: ";
	std::cout << stringPTR << std::endl << std::endl;

	std::cout << "Memory address of stringREF: ";
	std::cout << &stringREF << std::endl << std::endl;

	std::cout << "Value of str: ";
	std::cout << str << std::endl << std::endl;

	std::cout << "Value of stringPTR: ";
	std::cout << *stringPTR << std::endl << std::endl;

	std::cout << "Value of stringREF: ";
	std::cout << stringREF << std::endl << std::endl;

	return (1);
}
