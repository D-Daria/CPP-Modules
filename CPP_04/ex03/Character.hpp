#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class ICharacter;

# define MAX_SLOTS 4
# define MAX_STORAGE 100

class Character : public ICharacter {

	private:
		AMateria *m_slots[MAX_SLOTS];
		AMateria *m_floor[MAX_STORAGE];
		std::string m_name;

	public:
		Character();
		Character(const Character &copyCharacter);
		Character &operator=(const Character &character);
		virtual ~Character();

		Character(const std::string &name);
		virtual std::string const & getName() const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

		void displaySlots(void);
};

#endif