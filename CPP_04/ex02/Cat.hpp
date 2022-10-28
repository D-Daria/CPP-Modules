#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

	private:
		Brain *m_brain;

	public:
		Cat();
		Cat(const Cat &catCpoy);
		Cat &operator=(const Cat &cat);
		virtual ~Cat();

		virtual void makeSound(void) const;
		void setIdea(std::string idea, int pos);
		std::string getIdea(int pos);
		void getIdeas(void);
		void getIdeasAddress(void);
};

#endif