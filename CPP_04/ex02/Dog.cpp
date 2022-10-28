#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	m_type = "Dog";
	std::cout << YELLOW << getType() << " constructor called" << RESET << std::endl;
	m_brain = new Brain();
	if (m_brain == nullptr)
	{
		std::cerr << "Brain allocation failed" << std::endl;
		exit(-1);
	}
}

Dog::Dog(const Dog &copyDog) : AAnimal(copyDog)
{
	m_type = copyDog.getType();
	std::cout << YELLOW << m_type << " copy constructor called" << RESET << std::endl;
	m_brain = new Brain();
	if (m_brain == nullptr)
	{
		std::cerr << "Brain allocation failed" << std::endl;
		exit(-1);
	}
	for (size_t i = 0; i < IDEAS_SIZE; i++)
	{
		m_brain->setIdea(copyDog.m_brain->getIdea(i), i);
	}
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this == &dog)
		return (*this);
	m_type = dog.getType();
	std::cout << YELLOW << m_type << " assignment operator called" << RESET << std::endl;
	delete m_brain;
	m_brain = new Brain();
	if (m_brain == nullptr)
	{
		std::cerr << "Brain allocation failed" << std::endl;
		exit(-1);
	}
	for (size_t i = 0; i < IDEAS_SIZE; i++)
		m_brain->setIdea(dog.m_brain->getIdea(i), i);
	return (*this);
}

Dog::~Dog()
{
	std::cout << YELLOW << getType() << " destructor called" << RESET << std::endl;
	delete m_brain;
}

void Dog::makeSound(void) const
{
	std::cout << YELLOW << "Woof!" << RESET << std::endl;
}

void Dog::setIdea(std::string idea, int pos)
{
	if (pos >= 0 && pos < 100)
		m_brain->setIdea(idea, pos);
}

std::string Dog::getIdea(int pos)
{
	if (pos < 0 || pos > 100)
		return ("");
	return (m_brain->getIdea(pos));
}

void Dog::getIdeas(void)
{
	std::cout << YELLOW;
	for (size_t i = 0; i < IDEAS_SIZE; i++)
	{
		if (m_brain->getIdea(i).length() > 0)
			std::cout << m_brain->getIdea(i) << std::endl;
	}
	std::cout << RESET;
}

void Dog::getIdeasAddress(void)
{
	std::cout << YELLOW;
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
