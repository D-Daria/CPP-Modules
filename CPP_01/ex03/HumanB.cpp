#include "HumanB.hpp"

HumanB::HumanB(std::string p_name)
{
	name = p_name;
	setIsArmed(false);
}

HumanB::~HumanB(void)
{
	std::cout << name << " dropped the weapon: " << weapon->getType() << std::endl;
	std::cout << std::endl;
}

void HumanB::attack(void)
{
	if (getIsArmed() == true)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " better runs away" << std::endl;
}

void HumanB::setWeapon(Weapon &p_weapon)
{
	weapon = &p_weapon;
	setIsArmed(true);
}

void	HumanB::setIsArmed(bool opt)
{
	isArmed = opt;
}

bool	HumanB::getIsArmed(void)
{
	return (isArmed);
}
