#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

#include <cstdlib>
#include <time.h>

# define PPF_SIGN 25
# define PPF_EXEC 5

class PresidentialPardonForm : public Form {

	private:
		const std::string m_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copyPPF);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &ppf);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);

		virtual void execute(Bureaucrat const &executor) const;
		std::string getTarget(void) const;
};

#endif