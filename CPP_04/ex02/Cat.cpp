#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	m_type = "Cat";
	std::cout << CYAN << getType() << " constructor called" << RESET << std::endl;
	m_brain = new Brain();
	if (m_brain == nullptr)
	{
		std::cerr << "Brain allocation failed" << std::endl;
		exit(-1);
	}
}

Cat::Cat(const Cat &copyCat) : AAnimal(copyCat)
{
	std::cout << CYAN << m_type << " copy constructor called" << RESET << std::endl;
	m_type = copyCat.getType();
	m_brain = new Brain();
	if (m_brain == nullptr)
	{
		std::cerr << "Brain allocation failed" << std::endl;
		exit(-1);
	}
	for (size_t i = 0; i < IDEAS_SIZE; i++)
		m_brain->setIdea(copyCat.m_brain->getIdea(i), i);
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this == &cat)
		return (*this);
	m_type = cat.getType();
	std::cout << CYAN << m_type << " assignment operator called" << RESET << std::endl;
	delete m_brain; // delete null safe
	m_brain = new Brain();
	if (m_brain == nullptr)
	{
		std::cerr << "Brain allocation failed" << std::endl;
		exit(-1);
	}
	for (size_t i = 0; i < IDEAS_SIZE; i++)
		m_brain->setIdea(cat.m_brain->getIdea(i), i);
	return (*this);
}

Cat::~Cat()
{
	std::cout << CYAN << getType() << " destructor called" << RESET << std::endl;
	delete m_brain;
}

void Cat::makeSound(void) const
{
	std::cout << CYAN << "Meow!" << RESET << std::endl;
}

void Cat::setIdea(std::string idea, int pos)
{
	if (pos >= 0 && pos < 100)
		m_brain->setIdea(idea, pos);
}

std::string Cat::getIdea(int pos)
{
	if (pos < 0 || pos > 100)
		return ("");
	return (m_brain->getIdea(pos));
}

void Cat::getIdeas(void)
{
	std::cout << CYAN;
	for (size_t i = 0; i < IDEAS_SIZE; i++)
	{
		if (m_brain->getIdea(i).length() > 0)
			std::cout << m_brain->getIdea(i) << std::endl;
	}
	std::cout << RESET;
}

void Cat::getIdeasAddress(void)
{
	std::cout << CYAN;
	std::string str;

	for (size_t i = 0; i < IDEAS_SIZE; i++)
	{
		if (m_brain->getIdea(i).length() > 0)
		{
			str = m_brain->getIdea(i);
			std::cout << &str << std::endl;
		}
	}
	std::cout << RESET;
}
