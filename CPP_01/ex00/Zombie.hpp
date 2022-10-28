#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"

#include <string>
#include <iostream>

class Zombie {

	private:
		std::string	name;
	
	public:
		Zombie(std::string name);
		void announce(void);
		~Zombie(void);
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif