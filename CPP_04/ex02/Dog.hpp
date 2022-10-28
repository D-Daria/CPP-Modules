#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

	private:
		Brain *m_brain;

	public:
		Dog();
		Dog(const Dog &dogCopy);
		Dog &operator=(const Dog &dog);
		virtual ~Dog();

		virtual void makeSound(void) const;
		void setIdea(std::string idea, int pos);
		std::string getIdea(int pos);
		void getIdeas(void);
		void getIdeasAddress(void);
};

#endif