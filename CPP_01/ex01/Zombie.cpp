#include "Zombie.hpp"

//Default constructor
Zombie::Zombie(){};

//Destructor
Zombie::~Zombie()
{
	std::cout << RED << getName() << " number: " << getNumber() << " was defeated!" << RESET << std::endl;
}

void	Zombie::announce()
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ... " << "number: " << getNumber() << std::endl;
}

void	Zombie::setName(std::string z_name)
{
	name = z_name;
}

std::string	Zombie::getName(void)
{
	return (name);
}

void	Zombie::setNumber(int N)
{
	number = N;
}

int	Zombie::getNumber(void)
{
	return (number);
}
