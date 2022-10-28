#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	private:
		static const int m_fragHitPoints;
		static const int m_fragAttackDamage;

	public:
		FragTrap();
		FragTrap(const FragTrap &fragTrapCopy);
		FragTrap &operator=(const FragTrap &fragTrap);
		virtual ~FragTrap();

		FragTrap(std::string name);
		void highFivesGuys(void);
		int getFragHitPoints(void) const;
		int getFragAttackDamage(void) const;
};

#endif