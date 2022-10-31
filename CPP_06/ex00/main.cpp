#include "Conversion.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << RED << "Invalid number of arguments. Usage: ./convert [arg]" << RESET << std::endl;
		return (0);
	}
	std::string str = argv[1];
	try
	{
		Conversion convert(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	return (1);
}