#include "Harl.hpp"

int main(void)
{
	Harl harl;
	std::string level = "";

	std::cout << "Choose your option for Harl: ";
	std::cout << YELLOW << "[DEBUG] [INFO] [WARNING] [ERROR]" << RESET << std::endl;
	std::getline(std::cin, level, '\n');
	if (level.length() == 0)
	{
		std::cout << "Harl shall have a rest" << std::endl;
		return (0);
	}
	harl.complain(level);
	return (1);
}
