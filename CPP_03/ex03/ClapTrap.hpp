#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

#ifndef COLORS_H
#define COLORS_H

#define RESET   "\033[0m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#endif

class ClapTrap {

	//make attributes protected so that they can be inherited
	protected:
		std::string m_name;
		int m_hitPoints;
		int m_energyPoints;
		int m_attackDamage;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap &clapTrap);
		ClapTrap &operator=(const ClapTrap &clapTrap);
		virtual ~ClapTrap();

		ClapTrap(std::string name);
		virtual void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif
