#include "Sed.hpp"

static int	throwError(const std::string error)
{
	std::cout << RED << error << RESET << std::endl;
	return (0);
}

int main(int argc, char *argv[])
{
	Sed sed;
	if (argc != 4)
		return (throwError("Invalid number of arguments"));
	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	if (filename.length() * s1.length() * s2.length() == 0)
		return (throwError("Strings shouldn't be empty"));
	if (sed.openFile(filename) == 0)
		return (throwError("Failed to open inFile"));
	if (sed.writeReplace(filename, s1, s2) == 0)
		return (throwError("Failed to open outFile"));
	return (1);
}
