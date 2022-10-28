#include "Harl.hpp"

Harl::Harl()
{
	std::cout << GREEN << "Harl at your service" << RESET << std::endl;
}

Harl::~Harl()
{
	std::cout << RED << "Harl was turned off (finally)" << RESET << std::endl;
}

void Harl::debug(void)
{
	std::cout << CYAN
		<< "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< RESET << std::endl;
}

void Harl::info(void)
{
	std::cout << CYAN
		<< "[INFO]\nI cannot believe adding extra bacon costs more money. "
			"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< RESET << std::endl;
}

void Harl::warning(void)
{
	std::cout << CYAN
		<< "[WARNING]\nI think I deserve to have some extra bacon for free. "
			"I’ve been coming for years whereas you started working here since last month."
		<< RESET << std::endl;
}

void Harl::error(void)
{
	std::cout << CYAN
		<< "[ERROR]\nThis is unacceptable! I want to speak to the manager now."
		<< RESET << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levelOptions[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	chooseLevel chooseLevel[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	for (int i = 0; i < LEVELS_NUM; i++)
	{
        if (level == levelOptions[i])
		{
			(this->*chooseLevel[i])();
			return ;
		}
	}
	std::cout << CYAN << "There is nothing I can complain about" << RESET << std::endl;
}
