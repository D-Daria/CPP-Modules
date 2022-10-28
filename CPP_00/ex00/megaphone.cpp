#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	int		i;
	size_t	c;

	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		c = 0;
		std::string str(argv[i]);
		while (c < str.length())
		{
			std::cout << static_cast<char>(toupper(argv[i][c]));
			c++;
		}
		i++;
	}
	std::cout << std::endl;
	return (1);
}
