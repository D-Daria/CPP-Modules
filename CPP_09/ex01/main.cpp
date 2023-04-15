#include "RPN.hpp"

int main(int argc, char *argv[]) {

	(void)argv;

	if (argc != 2) {
		std::cerr << RED << "Error: invalid number of arguments" << std::endl;
		return 1;
	}

	std::string args(argv[1]);
	try
	{
		RPN rpn(args);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
