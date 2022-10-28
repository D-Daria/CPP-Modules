#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	m_keeperMode = 0;
	std::cout << YELLOW
			  << "ScavTrap default constructor called\n"
			  << "Default ScavTrap stats: "
			  << "\n\thit points: " << m_hitPoints
			  << "\n\tenergy points: " << m_energyPoints
			  << "\n\tattackDamage: " << m_attackDamage
			  << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrapCopy) : ClapTrap(scavTrapCopy)
{
	m_keeperMode = scavTrapCopy.m_keeperMode;
	std::cout << YELLOW
			  << "ScavTrap copy constructor called"
			  << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	if (this == &scavTrap)
		return (*this);
	m_keeperMode = scavTrap.m_keeperMode;
	m_name = scavTrap.m_name;
	m_hitPoints = scavTrap.m_hitPoints;
	m_energyPoints = scavTrap.m_energyPoints;
	m_attackDamage = scavTrap.m_attackDamage;
	std::cout << YELLOW
			  << "ScavTrap overloaded assignment operator called"
			  << RESET << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW
			  << "ScavTrap " << m_name << " destructor called"
			  << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	m_keeperMode = 0;
	std::cout << YELLOW
			  << "ScavTrap " << m_name << " constructor called\n"
			  << "ScavTrap " << m_name << " stats: "
			  << "\n\thit points: " << m_hitPoints
			  << "\n\tenergy points: " << m_energyPoints
			  << "\n\tattackDamage: " << m_attackDamage
			  << RESET << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (m_energyPoints <= 0 || m_hitPoints <= 0)
	{
		std::cout << YELLOW << "ScavTrap " << m_name;
		if (m_energyPoints <= 0)
			std::cout << " ran out of energy ";
		else if (m_hitPoints <= 0)
			std::cout << " passed";
		std::cout << RESET << std::endl;
		return ;
	}
	m_energyPoints -= 1;
	std::cout << YELLOW
		<< "ScavTrap " << m_name << " damages " << target
		<< " by " << m_attackDamage << " points. "
		<< "Energy left: " << m_energyPoints
		<< std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << YELLOW;
	if (m_energyPoints <= 0 || m_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << m_name;
		if (m_energyPoints <= 0)
			std::cout << " ran out of energy ";
		else if (m_hitPoints <= 0)
			std::cout << " passed";
		std::cout << RESET << std::endl;
		return ;
	}
	if (m_keeperMode == 1)
		std::cout << "ScavTrap " << m_name << " has already set Gate keeper mode" << std::endl;
	else
	{
		m_keeperMode = 1;
		std::cout << "ScavTrap " << m_name << " is now in Gate keeper mode" << std::endl;
	}
	std::cout << RESET;
}
