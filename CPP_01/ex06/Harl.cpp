#include "Harl.hpp"

Harl::Harl()
{
	std::cout << GREEN << "HarlFilter is ready to filter" << RESET << std::endl;
}

Harl::~Harl()
{
	std::cout << RED << "HarlFilter stopped filtering" << RESET << std::endl;
}

void Harl::debug(void)
{
	std::cout << CYAN
		<< "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"
		<< RESET << std::endl;
}

void Harl::info(void)
{
	std::cout << CYAN
		<< "[INFO]\nI cannot believe adding extra bacon costs more money. "
			"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"
		<< RESET << std::endl;
}

void Harl::warning(void)
{
	std::cout << CYAN
		<< "[WARNING]\nI think I deserve to have some extra bacon for free. "
			"I’ve been coming for years whereas you started working here since last month.\n"
		<< RESET << std::endl;
}

void Harl::error(void)
{
	std::cout << CYAN
		<< "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n"
		<< RESET << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levelOptions[] = {
								"DEBUG", 
								"INFO", 
								"WARNING", 
								"ERROR"};
	chooseLevel chooseLevel[] = {&Harl::debug, \
								&Harl::info, \
								&Harl::warning, \
								&Harl::error};

	int lNum;
	for (lNum = 0; lNum < LEVELS_NUM; lNum++)
	{
	    if (level == levelOptions[lNum])
			break ;
	}
	switch (lNum)
	{
		case 0:
			(this->*chooseLevel[0])();
		case 1:
			(this->*chooseLevel[1])();
		case 2:
			(this->*chooseLevel[2])();
		case 3:
			(this->*chooseLevel[3])();
			break ;
		default:
			std::cout << CYAN << 
					"[ Probably complaining about insignificant problems ]" 
					<< RESET << std::endl;
			break ;
	}
}
