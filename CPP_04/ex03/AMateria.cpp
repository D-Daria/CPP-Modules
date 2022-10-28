#include "AMateria.hpp"

AMateria::AMateria()
{
	// std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copyMateria)
{
	m_type = copyMateria.m_type;
	// std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &amateria)
{
	if (this == &amateria)
		return (*this);
	m_type = amateria.m_type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : m_type(type)
{
	// std::cout << "AMateria with type " << getType() <<  " constructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (m_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Materia " << m_type << " will be applied on " << target.getName() << std::endl;
}
