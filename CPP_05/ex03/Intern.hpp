#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

class Form;

class Intern {

	public:
		Intern();
		Intern(const Intern &copyIntern);
		Intern &operator=(const Intern &intern);
		~Intern();

		Form *makeForm(std::string formName, std::string target);

		Form *newShrubberyCreationForm(std::string &target);
		Form *newRobotomyRequestForm(std::string &target);
		Form *newPresidentialPardonForm(std::string &target);

		class FormDoesntExistException : public std::exception {
			public:
				virtual const char* what() const throw()
				{
					return ("Intern failed to create form because form doesn't exist");
				}
		};

		private:
};

#endif