#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

#include <cstdlib>
#include <time.h>

# define REQ_SIGN 72
# define REQ_EXEC 45

class RobotomyRequestForm : public Form {

	private:
		const std::string m_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copyReq);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &req);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);

		virtual void execute(Bureaucrat const &executor) const;
		std::string getTarget(void) const;

		class RobotomyFailedException : std::exception {
			public:
				virtual const char* what() const throw()
				{
					return ("Robotomy failed");
				}
		};
};

#endif