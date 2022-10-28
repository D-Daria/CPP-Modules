#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	private:
		int	m_keeperMode;

	public:
		ScavTrap();
		ScavTrap(const ScavTrap &copyScavTrap);
		ScavTrap &operator=(const ScavTrap &ScavTrap);
		virtual ~ScavTrap();

		ScavTrap(std::string name);
		virtual void attack(const std::string &target);
		void guardGate();
};

#endif