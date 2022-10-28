#ifndef FORM_HPP
# define FORM_HPP

#include <string>

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {

	private:
		const std::string m_name;
		bool m_isSigned;
		const int m_gradeSign;
		const int m_gradeExecute;

	public:
		Form();
		Form(const Form &copyForm);
		Form &operator=(const Form &form);
		~Form();
		Form(const std::string &name, int gradeSign, int gradeExecute);

		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getGradeSign(void) const;
		int getGradeExecute(void) const;

		void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Form &form);

#endif