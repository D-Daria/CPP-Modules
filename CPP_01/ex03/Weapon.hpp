#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {

	private:
		std::string type;
	
	public:
		Weapon(const std::string p_type);
		std::string getType(void) const;
		void setType(const std::string p_type);
		~Weapon(void);
};

#endif