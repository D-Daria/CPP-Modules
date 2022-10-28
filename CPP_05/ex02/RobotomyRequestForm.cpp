#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
								Form("RobotomyRequestForm", REQ_SIGN, REQ_EXEC), m_target("default")
{
	// std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
									: Form("RobotomyRequestForm", REQ_SIGN, REQ_EXEC), m_target(target)
{
	// std::cout << "RobotomyRequestForm constructor with " << getTarget() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copyReq) :
			Form(copyReq.getName(), REQ_SIGN, REQ_EXEC), m_target(copyReq.getTarget())
{
	// std::cout << "RobotomyRequestForm copy constructor" << std::endl;
	*this = copyReq;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &req) 
{
	// std::cout << "RobotomyRequestForm assignment" << std::endl;
	if (this == &req)
		return (*this);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);

	try
	{
		std::srand(time(0));
		if ((std::rand() % 1000 + 1) % 2 != 0)
			throw(RobotomyFailedException());
		std::cout << GREEN << getTarget() 
				  << " has been robotomized successfully 50% of the time" 
				  << RESET << std::endl;
	}
	catch(RobotomyFailedException &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

std::string RobotomyRequestForm::getTarget(void) const 
{
	return (m_target);
}
