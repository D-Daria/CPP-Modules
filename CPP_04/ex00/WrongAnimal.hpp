#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"

class WrongAnimal {

	protected:
		std::string	m_type;
	
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copyWrongAnimal);
		WrongAnimal &operator=(const WrongAnimal &copyWrongAnimal);
		virtual ~WrongAnimal();

		void makeSound(void) const;
		std::string getType(void) const;
};

#endif