#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	private:
		int	m_keeperMode;
		static const int m_scavEnergyPoints;

	public:
		ScavTrap();
		ScavTrap(const ScavTrap &copyScavTrap);
		ScavTrap &operator=(const ScavTrap &ScavTrap);
		virtual ~ScavTrap();

		ScavTrap(std::string name);
		virtual void attack(const std::string &target);
		void guardGate();

		int getScavEnergyPoints(void) const;
};

#endif