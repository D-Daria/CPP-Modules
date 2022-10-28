#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
		: m_name("default"), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap default constructor." << std::endl;
	std::cout
			<< "ClapTrap default stats: "
			<< "\n\thit points: " << m_hitPoints
			<< "\n\tenergy points: " << m_energyPoints
			<< "\n\tattack damage: " << m_attackDamage
			<< std::endl << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	m_name = clapTrap.m_name;
	m_hitPoints = clapTrap.m_hitPoints;
	m_energyPoints = clapTrap.m_energyPoints;
	m_attackDamage = clapTrap.m_attackDamage;
	*this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	if (this == &clapTrap)
		return (*this);
	m_name = clapTrap.m_name;
	m_hitPoints = clapTrap.m_hitPoints;
	m_energyPoints = clapTrap.m_energyPoints;
	m_attackDamage = clapTrap.m_attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << CYAN << "ClapTrap " << m_name << " destructor." << RESET << std::endl;	
}

ClapTrap::ClapTrap(std::string name) 
		: m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap " << m_name << " constructor." << std::endl;
	std::cout
			<< "ClapTrap " << m_name << " stats: "
			<< "\n\thit points: " << m_hitPoints
			<< "\n\tenergy points: " << m_energyPoints
			<< "\n\tattack damage: " << m_attackDamage
			<< std::endl << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (m_energyPoints <= 0 || m_hitPoints <= 0)
	{
		std::cout << RED << "ClapTrap " << m_name;
		if (m_energyPoints <= 0)
			std::cout << " doesn't have enough energy to attack " << target;
		else if (m_hitPoints <= 0)
			std::cout << " is dead";
		std::cout << RESET << std::endl;
		return ;
	}
	m_energyPoints -= 1;
	std::cout
		<< "ClapTrap " << m_name << " attacks " << target
		<< " causing " << m_attackDamage << " points of damage! "
		<< "Energy left: " << m_energyPoints
		<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	m_hitPoints -= static_cast<int>(amount);
	if (m_hitPoints <= 0 || m_hitPoints <= 0)
	{
		std::cout << RED
			<< "ClapTrap " << m_name << " died!"
			<< RESET << std::endl;
		return ;
	}
	std::cout << BLUE
		<< "ClapTrap " << m_name << " takes " << amount << " points of damage. "
		<< "ClapTrap " << m_name << " has " << m_hitPoints << " hit points left"
		<< RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (m_energyPoints <= 0 || m_hitPoints <= 0)
	{
		std::cout << YELLOW << "ClapTrap " << m_name;
		if (m_energyPoints <= 0)
			std::cout << " doesn't have enough energy to repair.";
		else if (m_hitPoints <= 0)
			std::cout << " is already dead.";
		std::cout << RESET << std::endl;
		return ;
	}
	m_hitPoints += amount;
	m_energyPoints -= 1;
	std::cout << GREEN
		<< "ClapTrap " << m_name << " obtained " << amount << " hit points. "
		<< "ClapTrap " << m_name << " has now " << m_hitPoints << " hit points. "
		<< "Energy left: " << m_energyPoints
		<< RESET << std::endl;
}
