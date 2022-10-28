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
		int	number;

	public:
		Zombie();
		Zombie(std::string name);
		void setName(std::string z_name);
		void setNumber(int N);
		int getNumber(void);
		std::string getName();
		void announce(void);
		~Zombie(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif