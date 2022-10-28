#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


int main(void)
{
	// to show that Form class is abstract
	// {
	// 	Form a1 = Form("A1", 110, 5);
	// }
	Bureaucrat bob = Bureaucrat("Bob", 100);
	Bureaucrat barbara = Bureaucrat("Barbara", 50);
	Bureaucrat john = Bureaucrat("John", 10);
	Bureaucrat supreme = Bureaucrat("Supreme", 1);
	Bureaucrat mike = Bureaucrat("Mike", 146);
	Bureaucrat cog = Bureaucrat("Cog", 150);
	try
	{
		Bureaucrat guru = Bureaucrat("Guru", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	{
		std::cout << "---------------------------\n";
		std::cout << "---ShrubberyCreationForm---\n";
		std::cout << "---------------------------\n";

		Form *treeForm = new ShrubberyCreationForm("Garden");
		std::cout << *treeForm << std::endl;

		mike.signForm(*treeForm);
		cog.executeForm(*treeForm);

		//form isn't signed yet
		//call directly to form
		supreme.executeForm(*treeForm);
		try
		{
			treeForm->execute(supreme);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << '\n';
		}

		bob.signForm(*treeForm);
		supreme.signForm(*treeForm);

		std::cout << std::endl;
		mike.executeForm(*treeForm);
		barbara.executeForm(*treeForm);
		cog.executeForm(*treeForm);

		delete treeForm;
	}
	std::cout << std::endl;
	{
		std::cout << "---------------------------\n";
		std::cout << "----RobotomyRequestForm----\n";
		std::cout << "---------------------------\n";

		Form *robotomyForm = new RobotomyRequestForm("Factory");
		std::cout << *robotomyForm << std::endl;

		supreme.executeForm(*robotomyForm);
		barbara.signForm(*robotomyForm);

		barbara.executeForm(*robotomyForm);
		john.executeForm(*robotomyForm);
		delete robotomyForm;
	}
	std::cout << std::endl;
	{
		std::cout << "--------------------------\n";
		std::cout << "--PresidentialPardonForm--\n";
		std::cout << "--------------------------\n";

		Form *pardonForm = new PresidentialPardonForm("Arthur Dent");
		std::cout << *pardonForm << std::endl;

		try
		{
			pardonForm->execute(supreme);
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << '\n';
		}
		john.signForm(*pardonForm);
		john.signForm(*pardonForm);

		john.executeForm(*pardonForm);
		supreme.executeForm(*pardonForm);
		delete pardonForm;
	}
	return (1);
}
