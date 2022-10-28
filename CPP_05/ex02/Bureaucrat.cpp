#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Default"), m_grade(150)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : m_name(name), m_grade(grade)
{
	std::cout << "Bureaucrat " << getName() << " constructor" << std::endl;
	if (m_grade < HIGH_GRADE)
		throw(GradeTooHighException());
	if (m_grade > LOW_GRADE)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &copyBureaucrat) : m_name(copyBureaucrat.getName())
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
	m_grade = copyBureaucrat.getGrade();
	*this = copyBureaucrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	std::cout << "Bureaucrat assignment operator" << std::endl;
	if (this == &bureaucrat)
		return (*this);
	m_grade = bureaucrat.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << getName() << " destructor" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return (m_name);
}

int Bureaucrat::getGrade(void) const
{
	return (m_grade);
}

void Bureaucrat::decrementGrade(void)
{
	if (m_grade + 1 > LOW_GRADE)
		throw(GradeTooLowException());
	else
		m_grade += 1;
}

void Bureaucrat::incrementGrade(void)
{
	if (m_grade - 1 < HIGH_GRADE)
		throw(GradeTooHighException());
	else
		m_grade -= 1;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(std::exception &e)
	{
		std::cout << *this << " couldn’t sign form " << form.getName() << " because: ";
		std::cerr << RED << e.what() << RESET << '\n';
		return ;
	}
	std::cout << *this << " signed form " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
	}
	catch(std::exception &e)
	{
		std::cerr << *this << " couldn’t execute form " << form.getName() << " because: ";
		std::cerr << RED << e.what() << RESET << '\n';
		return ;
	}
	std::cout << *this << " executed form " << form.getName() << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat's grade is too low");
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
