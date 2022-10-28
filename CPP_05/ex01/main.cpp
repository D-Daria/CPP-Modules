#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	{
		Bureaucrat *sam = nullptr;
		Form *a = nullptr;
		Form *a1 = nullptr;
		try
		{
			sam = new Bureaucrat("Sam", 120);
			std::cout << *sam << std::endl;
			a = new Form("A", 130, 5);
			std::cout << *a << std::endl;
			a1 = new Form("A1", 110, 5);
			std::cout << *a1 << std::endl;
			sam->signForm(*a);
			std::cout << *a << std::endl;
			sam->signForm(*a1);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << '\n';
		}
		if (sam != nullptr)
			delete sam;
		if (a != nullptr)
			delete a;
		if (a1 != nullptr)
			delete a1;
	}
	std::cout << std::endl;
	{
		try
		{
			Form b = Form("B", 0, 10);
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
			Form c = Form("C", 150, 151);
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Bureaucrat barbara = Bureaucrat("Barbara", 3);
		std::cout << barbara << std::endl;
		Form b = Form("B", 1, 1);
		std::cout << b << std::endl;
		barbara.signForm(b);
		try
		{
			barbara.incrementGrade();
			barbara.incrementGrade();
			barbara.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << '\n';
		}
		barbara.signForm(b);
		std::cout << b << std::endl;
	}
	return (1);
}
