#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#include <string>
#include <iostream>

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	m_type;

	public:
		AMateria(std::string const &type);

		AMateria();
		AMateria(const AMateria &copyAMateria);
		AMateria &operator=(const AMateria &amateria);
		virtual ~AMateria();

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0; //pure virtual
		virtual void use(ICharacter& target);
};

#endif