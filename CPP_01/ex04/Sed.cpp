#include "Sed.hpp"

Sed::Sed(void){}

Sed::~Sed(void)
{
	if (inFile.is_open() == true)
	{
		inFile.close();
		std::cout << GREEN << "inFile was closed" << RESET << std::endl;
	}
	if (outFile.is_open() == true)
	{
		outFile.close();
		std::cout << GREEN << "outFile was closed" << RESET << std::endl;
	}
}

int	Sed::openFile(std::string filename)
{
	inFile.open(filename);
	if (inFile.is_open() == false)
		return (0);
	return (1);
}

int Sed::writeReplace(std::string &filename, std::string &s1, std::string &s2)
{
	std::string strCheck = "";
	std::string outFileName = filename + ".replace";

	outFile.open(outFileName, std::ios::out);
	if (outFile.is_open() == false)
		return (0);
	size_t oldPos = 0;
	while (std::getline(inFile, strCheck, '\0'))
	{
		oldPos = strCheck.find(s1);
		while (oldPos != std::string::npos)
		{
			strCheck.erase(oldPos, s1.length());
			strCheck.insert(oldPos, s2);
			oldPos = strCheck.find(s1, oldPos + s2.length());
		}
		outFile << strCheck;
	}
	return (1);
}
