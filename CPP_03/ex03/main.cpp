#include "DiamondTrap.hpp"

int main(void)
{
	{
		std::cout << "----------------" << std::endl;
		std::cout << "Testing ClapTrap" << std::endl;
		std::cout << "----------------" << std::endl;
		ClapTrap clappy("Clappy");
	}
	{
		std::cout << "----------------" << std::endl;
		std::cout << "Testing ScavTrap" << std::endl;
		std::cout << "----------------" << std::endl;
		ScavTrap scavvy("Scavvy");
	}
	{
		std::cout << "----------------" << std::endl;
		std::cout << "Testing FragTrap" << std::endl;
		std::cout << "----------------" << std::endl;
		FragTrap fraggy("Fraggy");
	}
	{
		std::cout << "-------------------" << std::endl;
		std::cout << "Testing DiamondTrap" << std::endl;
		std::cout << "-------------------" << std::endl;

		DiamondTrap def;

		def.attack("Random dude");
		def.whoAmI();
		def.highFivesGuys();
		def.guardGate();

		DiamondTrap *d;
		DiamondTrap dimmy("Dimmy");
		d = &dimmy;

		d->whoAmI();
		d->highFivesGuys();
		d->attack("closest aim");
		d->guardGate();
		d->guardGate();

		d->takeDamage(90);
		d->beRepaired(10);

		for (int i = 0; i < 46; i++)
		{
			if (i < 45)
				std::cout.setstate(std::ios_base::failbit);
			d->attack("orde");
			std::cout.clear();
		}
		d->takeDamage(19);
		d->beRepaired(1);
		d->beRepaired(1);
		d->takeDamage(2);
		d->beRepaired(1);
		d->takeDamage(2);

		std::cout << std::endl;

		DiamondTrap *dp = new DiamondTrap("Diamond_Pointer");

		dp->whoAmI();

		delete dp;
	}
	return (1);
}
