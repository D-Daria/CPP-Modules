#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# define SH_SIGN 145
# define SH_EXEC 137

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form {

	private:
		const std::string m_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copyShCF);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shcf);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);

		virtual void execute(Bureaucrat const &executor) const;
		std::string getTarget(void) const;
};

#endif