#pragma once

#include "AForm.h"


class Intern
{

public:
	class FormNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	Intern();
	Intern(const Intern& other);
	Intern& operator= (const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target) const;

};
