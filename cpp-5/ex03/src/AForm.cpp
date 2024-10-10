#include "AForm.h"
#include "Bureaucrat.h"


AForm::AForm()
	: m_name("n2042"),
	m_gradeToSign(Bureaucrat::s_minGrade),
	m_gradeToExecute(Bureaucrat::s_minGrade),
	m_isSigned(false)
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: m_name(name),
	m_gradeToSign(gradeToSign),
	m_gradeToExecute(gradeToExecute),
	m_isSigned(false)
{
}

AForm::AForm(const AForm& other)
	: m_name(other.m_name),
	m_gradeToSign(other.m_gradeToSign),
	m_gradeToExecute(other.m_gradeToExecute),
	m_isSigned(other.m_isSigned)
{
}

AForm& AForm::operator=(const AForm& other)
{
	m_isSigned = other.m_isSigned;
	return *this;
}

AForm::~AForm()
{
}

const std::string AForm::getName() const
{
	return m_name;
}

int AForm::getGradeToSign() const
{
	return m_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return m_gradeToExecute;
}

bool AForm::isSigned() const
{
	return m_isSigned;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (!m_isSigned)
	{
		if (bureaucrat.getGrade() > m_gradeToSign)
			throw (AForm::GradeTooLowException());
		m_isSigned = true;
	}
	else
		throw (AForm::AlreadySignedException());
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!isSigned())
		throw (AForm::NotSignedException());
	else if (executor.getGrade() > m_gradeToExecute)
		throw (AForm::GradeTooLowException());
	else
		beExecuted();
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	out << 
		"AForm " << AForm.getName()
		<< " - sign:" << AForm.getGradeToSign()
		<< " exec:" << AForm.getGradeToExecute()
		<< " signed:" << AForm.isSigned();
	return out;
}

const char* AForm::GradeTooLowException::what() const throw ()
{
	return "employee's grade is too low";
}

const char* AForm::AlreadySignedException::what() const throw ()
{
	return "form is already signed";
}

const char * AForm::NotSignedException::what() const throw ()
{
	return "form is not signed";
}
