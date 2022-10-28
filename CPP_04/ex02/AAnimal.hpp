#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class AAnimal {

	protected:
		std::string	m_type;
	
	public:
		AAnimal();
		AAnimal(const AAnimal &animalCopy);
		AAnimal &operator=(const AAnimal &animalCopy);
		virtual ~AAnimal();

		virtual void makeSound(void) const = 0; //pure virtual
		std::string getType(void) const;
};

#endif