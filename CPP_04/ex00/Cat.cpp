#include "Cat.hpp"

Cat::Cat() : Animal()
{
	m_type = "Cat";
	std::cout << CYAN << getType() << " constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &copyCat) : Animal(copyCat)
{
	*this = copyCat;
	std::cout << CYAN << m_type << " copy constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << CYAN << m_type << " assignment operator called" << RESET << std::endl;
	if (this == &cat)
		return (*this);
	m_type = cat.getType();
	return (*this);
}

Cat::~Cat()
{
	std::cout << CYAN << getType() << " destructor called" << RESET << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << CYAN << "Meow!" << RESET << std::endl;
}
