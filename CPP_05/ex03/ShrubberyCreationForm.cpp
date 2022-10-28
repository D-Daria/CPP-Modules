#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
					Form("ShrubberyCreationForm", SH_SIGN, SH_EXEC), m_target("default")
{
	// std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
				: Form("ShrubberyCreationForm", SH_SIGN, SH_EXEC), m_target(target)
{
	// std::cout << "ShrubberyCreationForm constructor with " << getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copyShCF) :
					Form(copyShCF.getName(), SH_SIGN, SH_EXEC), m_target(copyShCF.getTarget())
{
	// std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
	*this = copyShCF;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shcf) 
{
	// std::cout << "ShrubberyCreationForm assignment" << std::endl;
	if (this == &shcf)
		return (*this);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);

	std::string trees[] = {
		"            ,@@@@@@@,\n",
		"    ,,,.   ,@@@@@@/@@,  .oo8888o.\n",
		"  ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n",
		",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n",
		"%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n",
		"%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n",
		"`&%\\ ` /%&'    |.|        \\ '|8'\n",
		"    |o|        | |         | |\n",
		"    |.|        | |         | |\n",
		" _\\/ ._\\//__/_/  ,\\_//___\\/.  \\_//__/_\n"};

	std::ofstream outfile;
	outfile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	std::string outfileName = getTarget() + "_shrubbery";
	size_t len = sizeof(trees) / sizeof(std::string);
	try
	{
		outfile.open(outfileName, std::ios::out);
		for (std::string *it = &trees[0]; it != &trees[len]; ++it)
			outfile << *it;
	}
	catch(std::ofstream::failure &e)
	{
		std::cerr << RED << "Error openning file" << RESET << '\n';
		return ;
	}
	std::cout << GREEN << "Shrubs planted in the " << getTarget() << RESET << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const 
{
	return (m_target);
}
