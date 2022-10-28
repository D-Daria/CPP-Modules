#include "Dog.hpp"

Dog::Dog() : Animal()
{
	m_type = "Dog";
	std::cout << YELLOW << getType() << " constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &copyDog) : Animal(copyDog)
{
	*this = copyDog;
	std::cout << YELLOW << m_type << " copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << YELLOW << m_type << " assignment operator called" << RESET << std::endl;
	if (this == &dog)
		return (*this);
	m_type = dog.getType();
	return (*this);
}

Dog::~Dog()
{
	std::cout << YELLOW << getType() << " destructor called" << RESET << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << YELLOW << "Woof!" << RESET << std::endl;
}
