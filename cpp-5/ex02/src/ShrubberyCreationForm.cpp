#include "ShrubberyCreationForm.h"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", s_gradeToSign, s_gradeToExecute)
	, m_target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", s_gradeToSign, s_gradeToExecute)
	, m_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), m_target(other.m_target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	this->m_target = other.m_target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return m_target;
}

void ShrubberyCreationForm::beExecuted() const
{
	std::ofstream outf((m_target + "_shrubbery").c_str());
	if (!outf)
		return;
	outf <<
"    *\n"
"   /.\\\n"
"  /o..\\\n"
"  /..o\\\n"
" /.o..o\\\n"
" /...o.\\\n"
"/..o....\\\n"
"^^^[_]^^^\n";
}
