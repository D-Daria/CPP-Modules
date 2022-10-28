#include "Zombie.hpp"

//Contructor
Zombie::Zombie(std::string z_name)
{
	name = z_name;
	std::cout << CYAN << name << RESET << " is coming..."  << std::endl;
}

//Desctructor
Zombie::~Zombie()
{
	std::cout << RED << name << " was defeated!" << RESET << std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n" << std::endl;
}
