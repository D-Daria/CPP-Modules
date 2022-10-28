#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {

	public:
		Cure();
		Cure(const Cure &copyCure);
		Cure &operator=(const Cure &cure);
		virtual ~Cure();

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);

	private:
};

#endif