#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

# define HIGH_GRADE	1
# define LOW_GRADE	150

#include <exception>
#include <string>
#include <iostream>

#include "Form.hpp"
class Form;

class Bureaucrat {

	private:
		const std::string m_name;
		int m_grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copyBureaucrat);
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);
		~Bureaucrat();

		Bureaucrat(const std::string &name, int grade);

		std::string getName(void) const;
		int getGrade(void) const;

		void incrementGrade(void);
		void decrementGrade(void);

		void signForm(Form &form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif