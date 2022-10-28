#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor" << std::endl;
}

Intern::Intern(const Intern &copyIntern)
{
	(void)copyIntern;
	std::cout << "Intern copy constructor" << std::endl;
}

Intern &Intern::operator=(const Intern &intern)
{
	std::cout << "Intern assignment" << std::endl;
	if (this == &intern)
		return (*this);
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Form *Intern::newShrubberyCreationForm(std::string &target)
{
	Form *newForm = new ShrubberyCreationForm(target);
	return (newForm);
}

Form *Intern::newRobotomyRequestForm(std::string &target)
{
	Form *newForm = new RobotomyRequestForm(target);
	return (newForm);
}

Form *Intern::newPresidentialPardonForm(std::string &target)
{
	Form *newForm = new PresidentialPardonForm(target);
	return (newForm);
}

Form *Intern::makeForm(std::string formName, std::string formTarget)
{
	typedef Form *(Intern::*Forms)(std::string &formTarget);

	Forms forms[3] = {&Intern::newShrubberyCreationForm,
					  &Intern::newRobotomyRequestForm,
					  &Intern::newPresidentialPardonForm};
	std::string formsNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form *newForm = nullptr;
	for (int i = 0; i < 3; i++)
	{
		if (formsNames[i].compare(formName) == 0)
		{
			newForm = (this->*(forms[i]))(formTarget);
			break ;
		}
	}
	try
	{
		if (newForm == nullptr)
			throw(Intern::FormDoesntExistException());
		std::cout << "Intern creates " << newForm->getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
		return (nullptr);
	}
	return (newForm);
}
