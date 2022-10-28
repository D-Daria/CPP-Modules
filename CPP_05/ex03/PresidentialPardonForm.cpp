#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
							Form("PresidentialPardonForm", PPF_SIGN, PPF_EXEC), m_target("default")
{
	// std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
					: Form("PresidentialPardonForm", PPF_SIGN, PPF_EXEC), m_target(target)
{
	// std::cout << "PresidentialPardonForm constructor with " << getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copyPPF) :
					Form(copyPPF.getName(), PPF_SIGN, PPF_EXEC), m_target(copyPPF.getTarget())
{
	// std::cout << "PresidentialPardonForm copy constructor" << std::endl;
	*this = copyPPF;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf) 
{
	// std::cout << "PresidentialPardonForm assignment" << std::endl;
	if (this == &ppf)
		return (*this);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);

	std::cout << GREEN << getTarget() << " was pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const 
{
	return (m_target);
}
