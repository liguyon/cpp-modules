#include "PresidentialPardonForm.h"
#include <iostream>


PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", s_gradeToSign, s_gradeToExecute)
	, m_target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", s_gradeToSign, s_gradeToExecute)
	, m_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), m_target(other.m_target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	this->m_target = other.m_target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return m_target;
}

void PresidentialPardonForm::beExecuted() const
{
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
