#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

# define MAGENTA "\033[35m"
# define RESET   "\033[0m"

# define IDEAS_SIZE 100

class Brain {

	private:
		std::string m_ideas[IDEAS_SIZE];
	
	public:
		Brain();
		Brain(const Brain &copyBrain);
		Brain &operator=(const Brain &brain);
		virtual ~Brain();

		void setIdea(std::string idea, int pos);
		std::string getIdea(int pos);
};

#endif