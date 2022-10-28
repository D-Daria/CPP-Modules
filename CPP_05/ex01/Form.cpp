#include "Form.hpp"

Form::Form() : m_name("default"), m_gradeSign(150), m_gradeExecute(150)
{
	m_isSigned = false;
	std::cout << BLUE << "Form " << getName() << " constructor" << std::endl;
}

Form::Form(const std::string &name, int gradeSign, int gradeExecute) :
						m_name(name), m_gradeSign(gradeSign), m_gradeExecute(gradeExecute)
{
	m_isSigned = false;
	std::cout << BLUE << "Form " << getName() << " constructor" << RESET << std::endl;
	if (m_gradeSign < HIGH_GRADE || m_gradeExecute < HIGH_GRADE)
		throw(GradeTooHighException());
	if (m_gradeSign > LOW_GRADE || m_gradeExecute > LOW_GRADE)
		throw(GradeTooLowException());
}

Form::Form(const Form &form) : 
		m_name(form.getName()), m_gradeSign(form.getGradeSign()), m_gradeExecute(form.getGradeExecute())
{
	std::cout << BLUE << "Form " << getName() << " copy constructor" << RESET << std::endl;
	m_isSigned = form.getIsSigned();
	*this = form;
}

Form &Form::operator=(const Form &form)
{
	std::cout << BLUE << "Form " << getName() << " assignment operator" << std::endl;
	if (this == &form)
		return (*this);
	m_isSigned = form.getIsSigned();
	return (*this);
}

Form::~Form()
{
	std::cout << BLUE << "Form " << getName() << " destructor" << RESET << std::endl;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (getIsSigned() == true)
		return ;
	if (bureaucrat.getGrade() > getGradeSign())
		throw(Form::GradeTooLowException());
	else if (bureaucrat.getGrade() < 1)
		throw(Form::GradeTooHighException());
	else
		m_isSigned = true;
}

std::string Form::getName(void) const
{
	return (m_name);
}

bool Form::getIsSigned(void) const
{
	return (m_isSigned);
}

int Form::getGradeSign(void) const
{
	return (m_gradeSign);
}

int Form::getGradeExecute(void) const
{
	return (m_gradeExecute);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high to process the form");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low to process the form");
}

std::ostream &operator<<(std::ostream& os, Form &form)
{
	std::cout << BLUE
			  << "Form " << form.getName() << " specifications:" << "\n"
			  << "\tGrade Sign:\t" << form.getGradeSign() << "\n"
			  << "\tGrade Execute:\t" << form.getGradeExecute() << "\n"
			  << "\tForm signed:\t" << form.getIsSigned()
			  << RESET;
	return os;
}
