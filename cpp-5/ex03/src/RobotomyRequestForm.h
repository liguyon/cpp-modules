#pragma once

#include "AForm.h"
#include "Bureaucrat.h"
#include <string>


class RobotomyRequestForm : public AForm
{

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator= (const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	const std::string& getTarget() const;
	void beExecuted() const;

private:
	std::string m_target;
	static const int s_gradeToSign = 72;
	static const int s_gradeToExecute = 45;
};
