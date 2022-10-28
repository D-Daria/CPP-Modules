#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	m_type = "WrongCat";
	std::cout << RED << getType() << " constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &copyWrongCat) : WrongAnimal(copyWrongCat)
{
	*this = copyWrongCat;
	std::cout << RED << m_type << " copy constructor called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
	if (this == &wrongCat)
		return (*this);
	m_type = wrongCat.getType();
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << RED << getType() << " destructor called" << RESET << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << RED << "Meow!" << RESET << std::endl;
}
