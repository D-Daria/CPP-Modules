#include "FragTrap.hpp"

const int FragTrap::m_fragHitPoints = 100;
const int FragTrap::m_fragAttackDamage = 30;

FragTrap::FragTrap() : ClapTrap()
{
	this->m_hitPoints = 100;
	this->m_energyPoints = 100;
	this->m_attackDamage = 30;
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
	*this = fragTrapCopy;
	std::cout << GREEN
			  << "FragTrap copy constructor called"
			  << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
	if (this == &fragTrap)
		return (*this);
	this->m_name = fragTrap.m_name;
	this->m_hitPoints = fragTrap.m_hitPoints;
	this->m_energyPoints = fragTrap.m_energyPoints;
	this->m_attackDamage = fragTrap.m_attackDamage;
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
	this->m_hitPoints = 100;
	this->m_energyPoints = 100;
	this->m_attackDamage = 30;
	std::cout << GREEN
			  << "FragTrap known as " << m_name << " is constructed\n"
			  << "FragTrap known as " << m_name << " stats: "
			  << "\n\thit points: " << m_hitPoints
			  << "\n\tenergy points: " << m_energyPoints
			  << "\n\tattack damage: " << m_attackDamage
			  << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << GREEN
			  << "High fives for all from FragTrap " << m_name << "!"
			  << RESET << std::endl;
}

int FragTrap::getFragHitPoints(void) const
{
	return (m_fragHitPoints);
}

int FragTrap::getFragAttackDamage(void) const
{
	return (m_fragAttackDamage);
}
