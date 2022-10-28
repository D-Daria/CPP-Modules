#include "Bureaucrat.hpp"

int main(void)
{
	{
		Bureaucrat *sam = nullptr;
		try
		{
			sam = new Bureaucrat("Sam", 151);
			std::cout << sam << std::endl;
			sam->decrementGrade();
			std::cout << *sam << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		if (sam)
			delete sam;
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat mike = Bureaucrat("Mike", 0);
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat sam = Bureaucrat("Sam", 3);
			std::cout << sam << std::endl;
			sam.incrementGrade();
			std::cout << sam << std::endl;
			sam.decrementGrade();
			std::cout << sam << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Bureaucrat *john = nullptr;
		try
		{
			john = new Bureaucrat("John", 149);
			std::cout << CYAN << *john << RESET << std::endl;
			for (int i = 1; i <= 3; i++)
				john->incrementGrade();
			std::cout << CYAN << *john << RESET << std::endl;
			for (int i = 1; i <= 4; i++)
				john->decrementGrade();
			std::cout << CYAN << *john << RESET << std::endl;
			john->decrementGrade();
			std::cout << CYAN << *john << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		if (john)
			delete john;
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat barbara = Bureaucrat("Barbara", 10);
			std::cout << GREEN << barbara << RESET << std::endl;
			Bureaucrat cog = Bureaucrat("Cog", 5);
			std::cout << cog << std::endl;
			cog = barbara;
			std::cout << cog << std::endl;
			barbara = Bureaucrat("Top", -5);
			std::cout  << GREEN << barbara << RESET << std::endl;
			barbara.incrementGrade();
			std::cout << GREEN << barbara << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Bureaucrat mike = Bureaucrat("Mike", 150);
		try
		{
			mike.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Bureaucrat bob = Bureaucrat("Bob", 1);
		try
		{
			bob.incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	return (1);
}
