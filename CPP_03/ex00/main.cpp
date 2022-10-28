#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap def;

	def.attack("air");
	def.beRepaired(10);
	def.takeDamage(20);

	ClapTrap robot("Roboto");

	robot.attack("mill");
	for (int i = 0; i < 4; i++)
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

	robot.takeDamage(3);
	return (1);
}
