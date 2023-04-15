#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {

	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe pmergeMe(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
