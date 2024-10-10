#include "Bureaucrat.h"
#include "AForm.h"
#include <iostream>


Bureaucrat::Bureaucrat()
	: m_name("Some guy at the bottom"), m_grade(Bureaucrat::s_minGrade)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: m_name(name), m_grade(Bureaucrat::s_minGrade)
{
	if (grade > Bureaucrat::s_minGrade)
		throw(Bureaucrat::GradeTooLowException());
	else if (grade < Bureaucrat::s_maxGrade)
		throw(Bureaucrat::GradeTooHighException());
	else
		m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: m_name(other.getName()), m_grade(other.getGrade())
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	m_grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{
	return m_name;
}

int Bureaucrat::getGrade() const
{
	return m_grade;
}

void Bureaucrat::increment()
{
	if (m_grade - 1 < Bureaucrat::s_maxGrade)
		return throw(Bureaucrat::GradeTooHighException());
	--m_grade;
}

void Bureaucrat::decrement()
{
	if (m_grade + 1 > Bureaucrat::s_minGrade)
		return throw(Bureaucrat::GradeTooLowException());
	++m_grade;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << 
		"Bureaucrat (lv." << bureaucrat.getGrade() << ") " << bureaucrat.getName();
	return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << m_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << m_name
			<< " couldn't sign " << form.getName()
			<< ", because the " << e.what() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << m_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << m_name
			<< " couldn't execute " << form.getName()
			<< ", because the " << e.what() << "." << std::endl;
	}
	
}
