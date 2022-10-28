#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	
	private:
		Weapon	&weapon;
		std::string	name;
	
	public:
		//takes a weapon in its contructor
		HumanA(std::string p_name, Weapon &p_weapon);
		void attack(void);
		~HumanA(void);
};

#endif