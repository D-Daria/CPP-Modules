#include "AAnimal.hpp"

AAnimal::AAnimal() : m_type("Unknown Creature")
{
	std::cout << "AAnimal " << getType() << " constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copyAAnimal)
{
	*this = copyAAnimal;
	std::cout << getType() << " copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &aanimal)
{
	m_type = aanimal.getType();
	std::cout << getType() << " assignment operator called" << std::endl;
	if (this == &aanimal)
		return (*this);
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal " << getType() << " destructor called" << std::endl;
}

void AAnimal::makeSound(void) const
{
	std::cout << "¯\\_(ツ)_/¯" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (m_type);
}
