#include "Ice.hpp"

Ice::Ice()
{
	m_type = "ice";
	// std::cout << CYAN << "Ice with type " << m_type << " constructor called" << RESET << std::endl;
}

Ice::Ice(const Ice &copyIce)
{
	m_type = copyIce.getType();
	// std::cout << CYAN << "Ice with type " << m_type << " copy constructor called" << RESET << std::endl;
}

Ice &Ice::operator=(const Ice &ice)
{
	if (this == &ice)
		return (*this);
	m_type = ice.getType();
	return (*this);
}

Ice::~Ice()
{
	std::cout << CYAN << "Ice with type " << m_type << " destructor called" << RESET << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria *newIce = new Ice();
	return (newIce);
}

void Ice::use(ICharacter& target)
{
	std::cout << CYAN
			  << "* shoots an ice bolt at "
			  << target.getName() << " *"
			  << RESET << std::endl;
}
