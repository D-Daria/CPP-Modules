#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat dude = Bureaucrat("Dude", 20);
	Bureaucrat supreme = Bureaucrat("Supreme", 5);
	Bureaucrat bobby = Bureaucrat("Bobby", 140);
	Intern someRandomIntern;
	{
		Form* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		try
		{
			if (rrf)
			{
				std::cout << *rrf << std::endl;

				dude.executeForm(*rrf);
				dude.signForm(*rrf);

				bobby.executeForm(*rrf);
				dude.executeForm(*rrf);
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		if (rrf)
			delete rrf;
	}
	std::cout << std::endl;
	{
		Form* rrf;
		rrf = someRandomIntern.makeForm("robotomy", "Bender");

		if (rrf)
		{
			std::cout << *rrf << std::endl;
			delete rrf;
		}
	}
	std::cout << std::endl;
	{
		Form* pardon;
		pardon = someRandomIntern.makeForm("presidential pardon", "Android");

		try
		{
			if (pardon)
			{
				std::cout << *pardon << std::endl;
				dude.signForm(*pardon);
				dude.signForm(*pardon);
				dude.executeForm(*pardon);

				supreme.executeForm(*pardon);
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		if (pardon)
			delete pardon;
	}
	std::cout << std::endl;
	{
		Form* shrub;
		shrub = someRandomIntern.makeForm("shrubbery creation", "Backyard");
		try
		{
			if (shrub)
			{
				std::cout << *shrub << std::endl;
				supreme.executeForm(*shrub);
				bobby.signForm(*shrub);
				dude.signForm(*shrub);
				bobby.executeForm(*shrub);
				supreme.executeForm(*shrub);
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		if (shrub)
			delete shrub;
	}
	return (1);
}
