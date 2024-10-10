#include "Intern.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <cstddef>
#include <iostream>

typedef struct
{
	const std::string name;
	AForm* (*factory)(const std::string&);

} FormFactoryEntry;

static AForm* newShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* newPresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

static AForm* newRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static const FormFactoryEntry formFactories[3] = {
	{"ShrubberyCreationForm", newShrubberyCreationForm},
	{"RobotomyRequestForm", newRobotomyRequestForm},
	{"PresidentialPardonForm", newPresidentialPardonForm},
};

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern & Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	for (size_t i = 0; i < (sizeof formFactories / sizeof *formFactories); ++i)
	{
		if (formName == formFactories[i].name)
		{
			std::cout << "someone made " << formName << std::endl;
			return formFactories[i].factory(target);
		}
	}
	throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw ()
{
	return "form does not exist";
}
