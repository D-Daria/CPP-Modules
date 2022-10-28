#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	private:

	public:
		WrongCat();
		WrongCat(const WrongCat &copyWrongCat);
		WrongCat &operator=(const WrongCat &wrongCat);
		virtual ~WrongCat();

		void makeSound(void) const;

	private:

};

#endif