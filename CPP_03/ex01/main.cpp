#include "ScavTrap.hpp"

int main(void)
{
	{
		std::cout << "----------------" << std::endl;
		std::cout << "Testing ClapTrap" << std::endl;
		std::cout << "----------------" << std::endl;
		ClapTrap robot("Clappy");
		robot.attack("mill");
		robot.attack("mill");
		robot.attack("mill");
		robot.attack("mill");
		robot.takeDamage(5);
		robot.beRepaired(4);
		robot.takeDamage(5);
		robot.attack("scarecrow");
		robot.takeDamage(2);
		robot.attack("clown");
		robot.attack("mill");
		robot.takeDamage(1);
		robot.beRepaired(1);
		robot.beRepaired(1);
		robot.takeDamage(2);
	}
	{
		std::cout << "----------------" << std::endl;
		std::cout << "Testing ScavTrap" << std::endl;
		std::cout << "----------------" << std::endl;

		ScavTrap def;
		def.attack("air");

		ScavTrap scavvy = ScavTrap("Scavvy");
		for (int i = 0; i < 40; i++)
		{
			if (i < 39)
				std::cout.setstate(std::ios_base::failbit);
			scavvy.attack("bush");
			std::cout.clear();
		}
		scavvy.guardGate();
		scavvy.guardGate();
		scavvy.takeDamage(90);
		scavvy.beRepaired(10);
		scavvy.takeDamage(5);
		for (int i = 0; i < 7; i++)
		{
			if (i < 6)
				std::cout.setstate(std::ios_base::failbit);
			scavvy.beRepaired(5);
			std::cout.clear();
		}
		scavvy.takeDamage(49);
		scavvy.attack("goblin");
		scavvy.attack("goblin");
		scavvy.beRepaired(5);
		scavvy.takeDamage(1);

		ScavTrap refScav = ScavTrap("RefScav");
		ClapTrap &refClap = refScav;
		refClap.attack("someone");

		ScavTrap *st = new ScavTrap("ScavPointer");
		st->attack("quelqu'un");
		st->takeDamage(10);
		st->beRepaired(5);
		st->guardGate();
		for (int i = 0; i < 48; i++)
		{
			if (i < 47)
				std::cout.setstate(std::ios_base::failbit);
			st->attack("giant");
			std::cout.clear();
		}
		st->guardGate();
		delete st;
	}
	return (1);
}
