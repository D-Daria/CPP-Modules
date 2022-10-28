#include "Weapon.hpp"

//Constructor
Weapon::Weapon(const std::string p_type)
{
	type = p_type;
}

//Destructor
Weapon::~Weapon() {};

std::string Weapon::getType(void) const
{
	return (type);
}

void Weapon::setType(const std::string p_type)
{
	type = p_type;
}
