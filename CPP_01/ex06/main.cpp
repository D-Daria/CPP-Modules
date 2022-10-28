#include "Harl.hpp"

static int	displayMessage(const std::string &msg, const std::string color)
{
	std::cout << color << msg << RESET << std::endl;
	return (0);
}

int main(int argc, char *argv[])
{
	Harl harlFilter;
	if (argc > 2)
		return (displayMessage("[This to much for me. I'm DONE]", CYAN));
	if (argc < 2)
		return (displayMessage("[ HarlFilter has nothing to filter ]", CYAN));
	std::string level(argv[1]);
	harlFilter.complain(level);
	return (1);
}
