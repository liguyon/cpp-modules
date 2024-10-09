#pragma once

#include "AForm.h"
#include "Bureaucrat.h"
#include <string>


class ShrubberyCreationForm : public AForm
{

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator= (const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	const std::string& getTarget() const;
	void beExecuted() const;

private:
	std::string m_target;
	static const int s_gradeToSign = 145;
	static const int s_gradeToExecute = 137;
};
