#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){};
PhoneBook::~PhoneBook(void){};

void	PhoneBook::setGlobalIndex(int index)
{
	c_index = index;
}

int	PhoneBook::getGlobalIndex(void)
{
	return (c_index);
}

void	PhoneBook::setDefaultContacts(void)
{
	int	i;

	i = -1;
	while (++i < CONTACT_MAX)
		contacts[i].setIsCreated(false);
}

static std::string	truncString(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(10);
		str[9] = '.';
	}
	return (str);
}

static int	validateNumber(std::string num)
{
	int	i;

	i = -1;
	while (num[++i])
	{
		if (!isdigit(num[i]))
			return (0);
	}
	return (1);
}

static int	validateString(std::string str)
{
	int	i;
	int	isChar = 0;

	i = -1;
	while (str[++i])
	{
		if (isascii(str[i]) && !isspace(str[i]))
			isChar++;
	}
	if (isChar == 0)
		return (0);
	return (1);
}

void PhoneBook::displayAvailableContacts(void)
{
	int	i;
	std::string str = "";

	std::cout << BOLDYELLOW;
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|";
	std::cout << BREAK << std::endl;
	i = -1;
	while (++i < CONTACT_MAX)
	{
		if (contacts[i].getIsCreated() == true)
		{
			str = contacts[i].getFirstName();
			std::cout << std::setw(10) << contacts[i].getIndex() << "|";
			std::cout << std::setw(10) << truncString(str) << "|";
			str = contacts[i].getLastName();
			std::cout << std::setw(10) << truncString(str) << "|";
			str = contacts[i].getNickname();
			std::cout << std::setw(10) << truncString(str) << "|" << std::endl;
		}
	}
}

int	PhoneBook::displayByIndex(void)
{
	std::string str = "";
	int index = 0;

	while (true)
	{
		std::cout << "Enter index of the contact to display: " << std::endl;
		if (std::cin.peek() == EOF)
		{
			std::cin.clear();
			std::cout << YELLOW << "Return to main menu" << BREAK << std::endl;
			return (EOF);
		}
		std::getline(std::cin, str);
		if (str.length() == 0)
			continue ;
		index = std::atoi(str.c_str());
		if (index < 0 || index > 7 || !validateNumber(str))
			std::cout << RED << "Invalid index. Try again." << BREAK << std::endl;
		else if (contacts[index].getIsCreated() == true)
		{
			std::cout << YELLOW << "Index: " << BREAK << contacts[index].getIndex() << std::endl;
			std::cout << YELLOW << "First Name: " << BREAK;
			std::cout << contacts[index].getFirstName() << std::endl;
			std::cout << YELLOW << "Last Name: " << BREAK;
			std::cout << contacts[index].getLastName() << std::endl;
			std::cout << YELLOW << "Nickname: " << BREAK;
			std::cout << contacts[index].getNickname() << std::endl;
			std::cout << YELLOW << "Phone Number: " << BREAK;
			std::cout << contacts[index].getPhoneNumber() << std::endl;
			std::cout << YELLOW << "Darkest Secret: " << BREAK;
			std::cout << contacts[index].getDarkestSecret() << std::endl;
			break ;
		}
		else
		{
			std::cout << RED << "There is no contact by this index." << BREAK << std::endl;
			break ;
		}
	}
	return (1);
}

int	PhoneBook::addContact(void)
{
	int c_index = getGlobalIndex();

	std::string str = "";
	while (str == "")
	{
		std::cout << "Enter First Name" << std::endl;
		if (std::cin.peek() == EOF)
		{
			str = "";
			std::cin.clear();
			std::cout << YELLOW << "Return to main menu" << BREAK << std::endl;
			return (EOF);
		}
		std::getline(std::cin, str);
		if (!str.empty())
		{
			if (!validateString(str))
			{
				std::cout << RED << "Input has no characters" << BREAK << std::endl;
				str = "";
			}
			else
				contacts[c_index].setFirstName(str);
		}
	}
	str = "";
	while (str == "")
	{
		std::cout << "Enter Last Name" << std::endl;
		if (std::cin.peek() == EOF)
		{
			str = "";
			std::cin.clear();
			std::cout << YELLOW << "Return to main menu" << BREAK << std::endl;
			return (EOF);
		}
		std::getline(std::cin, str);
		if (!str.empty())
		{
			if (!validateString(str))
			{
				std::cout << RED << "Input has no characters" << BREAK << std::endl;
				str = "";
			}
			else
				contacts[c_index].setLastName(str);
		}
	}
	str = "";
	while (str == "")
	{
		std::cout << "Enter Nickname" << std::endl;
		if (std::cin.peek() == EOF)
		{
			str = "";
			std::cin.clear();
			std::cout << YELLOW << "Return to main menu" << BREAK << std::endl;
			return (EOF);
		}
		std::getline(std::cin, str);
		if (!str.empty())
		{
			if (!validateString(str))
			{
				std::cout << RED << "Input has no characters" << BREAK << std::endl;
				str = "";
			}
			else
				contacts[c_index].setNickname(str);
		}
	}
	str = "";
	while (str == "")
	{
		std::cout << "Enter Phone Number" << std::endl;
		if (std::cin.peek() == EOF)
		{
			str = "";
			std::cin.clear();
			std::cout << YELLOW << "Return to main menu" << BREAK << std::endl;
			return (EOF);
		}
		std::getline(std::cin, str);
		if (!str.empty())
		{
			if (!validateNumber(str))
			{
				std::cout << RED << "Invalid number format. Try again" << BREAK << std::endl;
				str = "";
			}
			else
				contacts[c_index].setPhoneNumber(str);
		}
	}
	str = "";
	while (str == "")
	{
		std::cout << "Enter your Darkest Secret" << std::endl;
		if (std::cin.peek() == EOF)
		{
			str = "";
			std::cin.clear();
			std::cout << YELLOW << "Return to main menu" << BREAK << std::endl;
			return (EOF);
		}
		std::getline(std::cin, str);
		if (!str.empty())
		{
			if (!validateString(str))
			{
				std::cout << RED << "Input has no characters" << BREAK << std::endl;
				str = "";
			}
			else
				contacts[c_index].setDarkestSecret(str);
		}
	}
	std::cout << GREEN << "Contact added" << BREAK << std::endl;
	contacts[c_index].setIsCreated(true);
	contacts[c_index].setIndex(c_index);
	c_index += 1;
	if (c_index > 7)
		c_index = 0;
	setGlobalIndex(c_index);
	return (1);
}
