#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public:
		FragTrap();
		FragTrap(const FragTrap &fragTrapCopy);
		FragTrap &operator=(const FragTrap &fragTrap);
		virtual ~FragTrap();

		FragTrap(std::string name);
		void highFivesGuys(void);
};

#endif