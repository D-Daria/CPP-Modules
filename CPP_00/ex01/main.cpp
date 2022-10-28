#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	PhoneBook phoneBook;
	phoneBook.setGlobalIndex(0);
	phoneBook.setDefaultContacts();
	std::string command = "";

	while (true)
	{
		std::cout << "Enter command: ";
		std::cout << YELLOW << "[ADD] [SEARCH] [EXIT]" << BREAK << std::endl;
		if (std::cin.peek() == EOF)
		{
			std::cout << BLUE << "EXIT" << BREAK << std::endl;
			std::cin.clear();
			break ;
		}
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0)
		{
			if (phoneBook.addContact() == EOF)
			{
				std::cout << BLUE << "EXIT" << BREAK << std::endl;
				break ;
			}
		}
		else if (command.compare("SEARCH") == 0)
		{
			phoneBook.displayAvailableContacts();
			if (phoneBook.displayByIndex() == EOF)
			{
				std::cout << BLUE << "EXIT" << BREAK << std::endl;
				std::cin.clear();
				break ;
			}
		}
		else if (command.compare("EXIT") == 0)
		{
			std::cout << BLUE << "EXIT" << BREAK << std::endl;
			break ;
		}
		else if (command.length() != 0)
			std::cout << RED << "Invalid command. Try again.\n" << BREAK << std::endl;
	}
	return (1);
}
