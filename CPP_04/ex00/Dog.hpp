#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

	public:
		Dog();
		Dog(const Dog &dogCopy);
		Dog &operator=(const Dog &dog);
		virtual ~Dog();

		virtual void makeSound(void) const;

	private:

};

#endif