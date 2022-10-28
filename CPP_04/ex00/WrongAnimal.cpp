#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : m_type("Wrong Creature")
{
	std::cout << "WrongAnimal " << getType() << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copyWrongAnimal)
{
	*this = copyWrongAnimal;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this == &wrongAnimal)
		return (*this);
	m_type = wrongAnimal.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << getType() << " destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "LOL!!!" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (m_type);
}
