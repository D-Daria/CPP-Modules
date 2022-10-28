#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < MAX_SLOTS; i++)
		m_slots[i] = nullptr;
	for (int i = 0; i < MAX_STORAGE; i++)
		m_floor[i] = nullptr;
	// std::cout << YELLOW << "Character default constructor called" << std::endl;
}

Character::Character(const Character &copyCharacter)
{
	for (int i = 0; i < MAX_SLOTS; i++)
		m_slots[i] = copyCharacter.m_slots[i]->clone();
	for (int i = 0; i < MAX_STORAGE; i++)
		m_floor[i] = copyCharacter.m_floor[i]->clone();
	m_name = copyCharacter.getName();
	// std::cout << YELLOW << "Character " << getName() << " copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &character)
{
	// std::cout << YELLOW << "Character " << getName() << " assignment called" << std::endl;
	if (this == &character)
		return (*this);
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		if (m_slots[i])
			delete m_slots[i];
		m_slots[i] = character.m_slots[i]->clone();
	}
	for (int i = 0; i < MAX_STORAGE; i++)
	{
		if (m_floor[i])
			delete m_floor[i];
		m_floor[i] = character.m_floor[i]->clone();
	}
	m_name = character.getName();
	std::cout << YELLOW << "Character " << getName() << " assignment called" << std::endl;
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		delete m_slots[i];
		m_slots[i] = nullptr;
	}
	for (int i = 0; i < MAX_STORAGE; i++)
	{
		delete m_floor[i];
		m_floor[i] = nullptr;
	}
	std::cout << YELLOW << "Character " << getName() << " destructor called" << std::endl;
}

Character::Character(const std::string &name) : m_name(name)
{
	for (int i = 0; i < MAX_SLOTS; i++)
		m_slots[i] = nullptr;
	for (int i = 0; i < MAX_STORAGE; i++)
		m_floor[i] = nullptr;
	// std::cout << YELLOW << "Character " << getName() << " constructor called" << std::endl;
}

std::string const &Character::getName() const
{
	return (m_name);
}

void Character::equip(AMateria *m)
{
	if (m == nullptr)
	{
		std::cout << YELLOW << "Materia doesn't exist" << RESET << std::endl;
		return ;
	}
	int i = -1;
	while (++i < MAX_SLOTS)
	{
		if (m_slots[i] == nullptr)
			break;
	}
	if (i > 3)
	{
		std::cout << YELLOW << "Character's " << m_name << " Inventory is full" << RESET << std::endl;
		if (m)
			delete m;
		return ;
	}
	m_slots[i] = m;
	std::cout << YELLOW << "Character " << getName()
			  <<" puts materia " << m->getType()
			  << " in slot " << "[" << i << "]"
			  << RESET << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << YELLOW << "Slot is out of bounds" << RESET << std::endl;
		return ;
	}
	if (m_slots[idx] != nullptr)
	{
		int i;
		for (i = 0; i < MAX_STORAGE; i++)
		{
			if (m_floor[i] == nullptr)
			{
				m_floor[i] = m_slots[idx];
				break ;
			}
		}
		if (i >= MAX_STORAGE)
		{
			std::cout << YELLOW 
					  << "Even floor doesn't have enough free space for that" 
					  << RESET << std::endl;
			return ;
		}
		m_slots[idx] = nullptr;
		std::cout << YELLOW << "Character " << getName()
			  <<" drops materia"
			  << " of slot [" << idx << "] on the floor"
			  << RESET << std::endl;
		return ;
	}
	std::cout << YELLOW
				  << "Character's " << getName() 
				  << " can't unequip empty slot [" << idx << "]" 
				  << RESET << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << YELLOW << "Slot is out of bounds" << RESET << std::endl;
		return ;
	}
	if (m_slots[idx])
		m_slots[idx]->use(target);
	else
		std::cout << YELLOW
				  << "Character's " << getName() 
				  << " slot [" << idx << "] is empty" 
				  << RESET << std::endl;
}

void Character::displaySlots(void)
{
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		std::cout << "Character " << m_name << " has [" << i << "]: " << m_slots[i] << std::endl;
	}
}
