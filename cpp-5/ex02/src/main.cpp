#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include <iostream>
#include <cassert>

int main()
{
	{ // TEST: basic tests
        std::cout << "==== TESTS: basic tests ====\n";
		ShrubberyCreationForm a;
		std::cout << a << std::endl;
		assert(a.getGradeToSign() == 145 && a.getGradeToExecute() == 137);

		RobotomyRequestForm b;
		std::cout << b << std::endl;
		assert(b.getGradeToSign() == 72 && b.getGradeToExecute() == 45);

		PresidentialPardonForm c;
		std::cout << c << std::endl;
		assert(c.getGradeToSign() == 25 && c.getGradeToExecute() == 5);
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: sign form
        std::cout << "==== TESTS: execute form ====\n";

		Bureaucrat bur("aliste", 140);
		Bureaucrat bur2("kina", 2);

		ShrubberyCreationForm a("nimal");
		bur.signForm(a);
		bur.executeForm(a);
		bur2.executeForm(a);

		RobotomyRequestForm b("lier");
		bur2.signForm(b);
		bur.executeForm(b);
		bur2.executeForm(b);

		PresidentialPardonForm c("leste");
		bur2.signForm(c);
		bur.executeForm(c);
		bur2.executeForm(c);
	}

	return 0;
}
