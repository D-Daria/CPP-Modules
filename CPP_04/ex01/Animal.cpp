#include "Animal.hpp"

Animal::Animal() : m_type("Unknown Creature")
{
	std::cout << "Animal " << getType() << " constructor called" << std::endl;
}

Animal::Animal(const Animal &copyAnimal)
{
	*this = copyAnimal;
	std::cout << getType() << " copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	m_type = animal.getType();
	std::cout << getType() << " assignment operator called" << std::endl;
	if (this == &animal)
		return (*this);
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal " << getType() << " destructor called" << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << "¯\\_(ツ)_/¯" << std::endl;
}

std::string Animal::getType(void) const
{
	return (m_type);
}
