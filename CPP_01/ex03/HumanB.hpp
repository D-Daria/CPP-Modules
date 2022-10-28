#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	
	private:
		Weapon	*weapon;
		std::string	name;
		bool	isArmed;

	public:
		HumanB(std::string p_name);
		~HumanB(void);
		void attack(void);
		void setWeapon(Weapon &p_weapon);
		void setIsArmed(bool opt);
		bool getIsArmed(void);
};

#endif