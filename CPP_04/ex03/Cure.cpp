#include "Cure.hpp"

Cure::Cure()
{
	m_type = "cure";
	// std::cout << GREEN << "Cure with type " << m_type << " constructor called" << RESET << std::endl;
}

Cure::Cure(const Cure &copyCure)
{
	m_type = copyCure.getType();
	// std::cout << GREEN << "Ice with type " << m_type << " copy constructor called" << RESET << std::endl;
}

Cure &Cure::operator=(const Cure &cure)
{
	if (this == &cure)
		return (*this);
	m_type = cure.getType();
	return (*this);
}

Cure::~Cure()
{
	std::cout << GREEN << "Cure with type " << m_type << " destructor called" << RESET << std::endl;
}

//returns a new instance of the same type
AMateria* Cure::clone() const
{
	AMateria *newCure = new Cure();
	return (newCure);
}

void Cure::use(ICharacter& target)
{
	std::cout << GREEN
			  << "* heals " << target.getName() << "’s wounds *" << RESET
			  << std::endl;
}
