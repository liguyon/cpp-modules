#include "RobotomyRequestForm.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", s_gradeToSign, s_gradeToExecute)
	, m_target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", s_gradeToSign, s_gradeToExecute)
	, m_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), m_target(other.m_target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	this->m_target = other.m_target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return m_target;
}

void RobotomyRequestForm::beExecuted() const
{
	std::cout << "*INSERT DRILLING NOISES* " << m_target << " has ";
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << "not ";
	std::cout << "been robotomized" << std::endl;
}
