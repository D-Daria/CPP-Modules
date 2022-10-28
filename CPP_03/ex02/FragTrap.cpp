#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	std::cout << GREEN
			  << "FragTrap default is constructed\n"
			  << "Default FragTrap stats: "
			  << "\n\thit points: " << m_hitPoints
			  << "\n\tenergy points: " << m_energyPoints
			  << "\n\tattack damage: " << m_attackDamage
			  << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrapCopy) : ClapTrap(fragTrapCopy)
{
	std::cout << GREEN
			  << "FragTrap copy constructor called"
			  << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
	if (this == &fragTrap)
		return (*this);
	m_name = fragTrap.m_name;
	m_hitPoints = fragTrap.m_hitPoints;
	m_energyPoints = fragTrap.m_energyPoints;
	m_attackDamage = fragTrap.m_attackDamage;
	std::cout << GREEN
			  << "FragTrap assignation called"
			  << RESET << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << GREEN
			  << "FragTrap known as " << m_name << " is destructed"
			  << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	std::cout << GREEN
			  << "FragTrap known as " << m_name << " is constructed\n"
			  << "FragTrap known as " << m_name << " stats: "
			  << "\n\thit points: " << m_hitPoints
			  << "\n\tenergy points: " << m_energyPoints
			  << "\n\tattackDamage: " << m_attackDamage
			  << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << GREEN;
	if (m_hitPoints <= 0 || m_energyPoints <= 0)
	{
		std::cout << "FragTrap " << m_name << " can't give high fives as ";
		if (m_energyPoints <= 0)
			std::cout << "it wasted all energy points";
		else if (m_hitPoints <= 0)
			std::cout << "it is dead";
		std::cout << RESET << std::endl;
		return;
	}
	std::cout << "High fives for all from FragTrap " << m_name << "!" << RESET << std::endl;
}
