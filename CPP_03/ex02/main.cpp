#include "FragTrap.hpp"

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
		std::cout << "Testing FragTrap" << std::endl;
		std::cout << "----------------" << std::endl;

		FragTrap def;
		def.attack("void");

		FragTrap fraggy = FragTrap("Fraggy");
		for (int i = 0; i < 40; i++)
		{
			if (i < 39)
				std::cout.setstate(std::ios_base::failbit);
			fraggy.attack("bush");
			std::cout.clear();
		}
		fraggy.highFivesGuys();

		fraggy.takeDamage(90);
		fraggy.beRepaired(10);

		fraggy.takeDamage(5);
		for (int i = 0; i < 7; i++)
		{
			if (i < 6)
				std::cout.setstate(std::ios_base::failbit);
			fraggy.beRepaired(5);
			std::cout.clear();
		}
		fraggy.takeDamage(49);
		fraggy.attack("goblin");
		fraggy.attack("goblin");
		for (int i = 0; i < 48; i++)
		{
			if (i < 47)
				std::cout.setstate(std::ios_base::failbit);
			fraggy.beRepaired(5);
			std::cout.clear();
		}
		fraggy.takeDamage(41);
		fraggy.attack("gargouille");
		fraggy.attack("gargouille");
		fraggy.beRepaired(10);
		fraggy.highFivesGuys();
		fraggy.takeDamage(200);

		FragTrap lastFrag = FragTrap("LastFrag");
	}
	return (1);
}
