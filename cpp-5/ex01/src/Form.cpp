#include "Form.h"
#include "Bureaucrat.h"


Form::Form()
	: m_name("n2042"),
	m_gradeToSign(Bureaucrat::s_minGrade),
	m_gradeToExecute(Bureaucrat::s_minGrade),
	m_isSigned(false)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: m_name(name),
	m_gradeToSign(gradeToSign),
	m_gradeToExecute(gradeToExecute),
	m_isSigned(false)
{
}

Form::Form(const Form& other)
	: m_name(other.m_name),
	m_gradeToSign(other.m_gradeToSign),
	m_gradeToExecute(other.m_gradeToExecute),
	m_isSigned(other.m_isSigned)
{
}

Form& Form::operator=(const Form& other)
{
	m_isSigned = other.m_isSigned;
	return *this;
}

Form::~Form()
{
}

const std::string Form::getName() const
{
	return m_name;
}

int Form::getGradeToSign() const
{
	return m_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return m_gradeToExecute;
}

bool Form::isSigned() const
{
	return m_isSigned;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (!m_isSigned)
	{
		if (bureaucrat.getGrade() > m_gradeToSign)
			throw(Form::GradeTooLowException());
		m_isSigned = true;
	}
	else
		throw(Form::AlreadySignedException());
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << 
		"Form " << form.getName()
		<< " - sign:" << form.getGradeToSign()
		<< " exec:" << form.getGradeToExecute()
		<< " signed:" << form.isSigned();
	return out;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "employee's grade is too low";
}

const char* Form::AlreadySignedException::what() const throw()
{
	return "form is already signed";
}
