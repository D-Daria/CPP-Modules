#include "Brain.hpp"

Brain::Brain()
{
	std::cout << MAGENTA << "Brain constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &copyBrain)
{
	std::cout << MAGENTA << "Brain copy constructor called" << RESET << std::endl;
	for (int i = 0; i < IDEAS_SIZE; i++)
		m_ideas[i] = copyBrain.m_ideas[i];
}

Brain &Brain::operator=(const Brain &copyBrain)
{
	std::cout << MAGENTA << "Brain assignment operator called" << RESET << std::endl;
	if (this == &copyBrain)
		return (*this);
	for (int i = 0; i < IDEAS_SIZE; i++)
		m_ideas[i] = copyBrain.m_ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << MAGENTA << "Brain destructor called" << RESET << std::endl;
}

void Brain::setIdea(std::string idea, int pos)
{
	if (pos >= 0 && pos < 100)
		m_ideas[pos] = idea;
}

std::string Brain::getIdea(int pos)
{
	if (pos < 0 || pos > 100)
		return ("");
	return (m_ideas[pos]);
}
