#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {

	public:
		Ice();
		Ice(const Ice &copyIce);
		Ice &operator=(const Ice &ice);
		virtual ~Ice();

		virtual AMateria* clone() const;		//from AMateria - returns a new instance of the same type
		virtual void use(ICharacter& target);	//from AMateria

	private:
};

#endif