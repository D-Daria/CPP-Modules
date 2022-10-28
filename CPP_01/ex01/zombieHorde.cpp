#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 1)
	{
		std::cout << "There must be at least one zombie" << std::endl;
		return (nullptr);
	}
	Zombie *zombies = new Zombie[N];
	if (zombies == nullptr)
	{
		std::cout << RED << "Zombies allocation failed" << std::endl;
		return (nullptr);
	}
	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
		zombies[i].setNumber(i + 1);
	}
	return (zombies);
}
