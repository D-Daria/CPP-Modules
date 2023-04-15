#include "BitcoinExchange.hpp"

void show_error(const std::string err_msg)
{
	std::cerr << RED << "Error: " << err_msg << RESET << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		show_error("could not open file.");
		return 0;
	}
	try
	{
		BitcoinExchange btc(static_cast<std::string>(argv[1]));
		btc.exchange();

	} catch(const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl ;
	}

	return 1;
}