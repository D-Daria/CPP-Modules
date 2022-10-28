#include "HumanB.hpp"
#include "HumanA.hpp"

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon club = Weapon("spear");
		HumanB Mike("Mike");
		Mike.attack();
		club.setType("spear");
		Mike.setWeapon(club);
		Mike.attack();
		club.setType("halberd");
		Mike.attack();
	}
	return (0);
}
