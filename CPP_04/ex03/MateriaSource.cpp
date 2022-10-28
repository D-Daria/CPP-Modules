#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_SLOTS; i++)
		m_materias[i] = nullptr;
	// std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copyMateriaSrc)
{
	for (int i = 0; i < MAX_SLOTS; i++)
		m_materias[i] = copyMateriaSrc.m_materias[i]->clone();
	// std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materia)
{
	// std::cout << "MateriaSource assignement called" << std::endl;
	if (this == &materia)
		return (*this);
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		if (m_materias[i] != nullptr)
			delete m_materias[i];
		m_materias[i] = m_materias[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		if (m_materias[i] != nullptr)
			delete m_materias[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
	int i = -1;
	while (++i < MAX_SLOTS)
	{
		if (m_materias[i] == nullptr)
			break;
	}
	if (i > 3)
	{
		std::cout << "MateriaSource slots are full" << std::endl;
		if (m)
			delete m;
		return ;
	}
	m_materias[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		if (m_materias[i]->getType() == type)
			return (m_materias[i]->clone());
	}
	std::cout << "MateriaSource can't create materia of " << type << std::endl;
	return (0);
}

void MateriaSource::getMateriaSources(void)
{
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		std::cout << "MateriaSource slot [" << i << "]: " << m_materias[i] << std::endl;
	}
}
