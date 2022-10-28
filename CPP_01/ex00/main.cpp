#include "Zombie.hpp"

int main(void)
{
	Zombie *brandNewZombie = newZombie("Brand New Zombie");
	if (brandNewZombie == nullptr)
	{
		std::cerr << "Failed to allocate object" << std::endl;
		return (0);
	}
	randomChump("Chumpy Zombie");
	delete brandNewZombie;
	return (1);
}
