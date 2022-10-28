#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_Diamond_clap_name"), ScavTrap(), FragTrap()
{
	this->m_name = "default_Diamond";
	this->m_hitPoints = FragTrap::getFragHitPoints();
	this->m_energyPoints = ScavTrap::getScavEnergyPoints();
	this->m_attackDamage = FragTrap::getFragAttackDamage();
	std::cout
			  << "----------------------------\n"
			  << "default_Diamond contructor\n"
			  << "default_Diamond stats: "
			  << "\n\thit points: " << m_hitPoints
			  << "\n\tenergy points: " << m_energyPoints
			  << "\n\tattack damage: " << m_attackDamage
			  << "\n----------------------------"
			  << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &dtCopy) : ClapTrap(dtCopy)
{
	*this = dtCopy;
	std::cout
			  << m_name << "_Diamond copy constructor"
			  << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt)
{
	std::cout
			  << m_name << "_Diamond assignation"
			  << RESET << std::endl;
	if (this == &dt)
		return (*this);
	this->m_name = dt.m_name;
	this->m_hitPoints = dt.m_hitPoints;
	this->m_energyPoints = dt.m_energyPoints;
	this->m_attackDamage = dt.m_attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamond " << m_name << " destructor" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), 
											ScavTrap(name), FragTrap(name)
{
	this->m_name = name;
	this->m_hitPoints = FragTrap::getFragHitPoints();
	this->m_energyPoints = ScavTrap::getScavEnergyPoints();
	this->m_attackDamage = FragTrap::getFragAttackDamage();
	std::cout
			  << "----------------------------\n"
			  << m_name << "_Diamond contructor\n"
			  << m_name << "_Diamond stats: "
			  << "\n\thit points: " << m_hitPoints
			  << "\n\tenergy points: " << m_energyPoints
			  << "\n\tattack damage: " << m_attackDamage
			  << "\n----------------------------"
			  << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout
			  << "The question is Who am I?\n"
			  << "\tI am Diamond " << m_name << "\n"
			  << "\tI am ClapTrap " << ClapTrap::m_name
			  << std::endl;
}
