#include "HumanA.hpp"

//A reference must always be binded to an object.
//We need to pass an object we want to have reference to in constructor.
HumanA::HumanA(std::string p_name, Weapon &p_weapon) : weapon(p_weapon)
{
	name = p_name;
}

HumanA::~HumanA(void)
{
	std::cout << name << " dropped the weapon: " << weapon.getType() << std::endl;
	std::cout << std::endl;
};

void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
