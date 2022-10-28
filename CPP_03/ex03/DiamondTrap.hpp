#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/*
	    ClapTrap
	   |       \
	  |         \
	 |           \
  ScavTrap    FragTrap
     \           |
	  \         |
	   \       |
	  DiamondTrap
*/

class DiamondTrap : public ScavTrap, public FragTrap {

	private:
		std::string m_name;

	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &DiamondTrapCopy);
		DiamondTrap &operator=(const DiamondTrap &DiamondTrap);
		virtual ~DiamondTrap();

		DiamondTrap(std::string name);
		void attack(const std::string &target);
		void whoAmI(void);
};

#endif