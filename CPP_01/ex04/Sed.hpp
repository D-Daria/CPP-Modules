#ifndef SED_HPP
# define SED_HPP

#include <string>
#include <iostream>
#include <fstream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

class Sed {

	private:
		std::ifstream inFile;
		std::ofstream outFile;

	public:
		Sed(void);
		int	openFile(std::string filename);
		int writeReplace(std::string &filename, std::string &s1, std::string &s2);
		~Sed(void);
};

#endif