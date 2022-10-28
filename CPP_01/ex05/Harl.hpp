#ifndef HARL_HPP
# define HARL_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

#include <iostream>
#include <string>

#define LEVELS_NUM 4

class Harl {

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl();
		void complain(std::string level);
		typedef void (Harl::*chooseLevel)();
		~Harl();
};

#endif