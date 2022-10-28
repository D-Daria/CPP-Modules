#include "Zombie.hpp"

int main(void)
{
	int N = 3;
	Zombie *zombies = zombieHorde(N, "Sir Zombie");
	if (zombies == nullptr)
	{
		std::cout << RED << "Zombies allocation failed" << RESET << std::endl;
		return (0);
	}
	//pointer to first zombie
	zombies->announce();
	for (int i = 0; i < N; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;

	zombies = zombieHorde(0, "ZERO");
	return (1);
}
