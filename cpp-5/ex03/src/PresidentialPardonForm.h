#pragma once

#include "AForm.h"
#include "Bureaucrat.h"
#include <string>


class PresidentialPardonForm : public AForm
{

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator= (const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	const std::string& getTarget() const;
	void beExecuted() const;

private:
	std::string m_target;
	static const int s_gradeToSign = 25;
	static const int s_gradeToExecute = 5;
};
