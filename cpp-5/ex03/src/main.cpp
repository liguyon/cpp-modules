#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "Intern.h"
#include <iostream>
#include <cassert>

int main()
{
	{ // TEST: intern shrubbery
        std::cout << "==== TESTS: intern shrubbery ====\n";

		Bureaucrat bur("a", 1);
		Intern mec;

		try
		{
			AForm* a = mec.makeForm("ShrubberyCreationForm", "tar");
			bur.signForm(*a);
			bur.executeForm(*a);
			delete a;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: intern robotomy
        std::cout << "==== TESTS: intern robotomy ====\n";

		Bureaucrat bur("a", 1);
		Intern mec;

		try
		{
			AForm* a = mec.makeForm("RobotomyRequestForm", "tar");
			bur.signForm(*a);
			bur.executeForm(*a);
			delete a;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: intern predisential pardon
        std::cout << "==== TESTS: intern predisential pardon ====\n";

		Bureaucrat bur("a", 1);
		Intern mec;

		try
		{
			AForm* a = mec.makeForm("PresidentialPardonForm", "tar");
			bur.signForm(*a);
			bur.executeForm(*a);
			delete a;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: intern err
        std::cout << "==== TESTS: intern err ====\n";

		Bureaucrat bur("a", 1);
		Intern mec;

		try
		{
			AForm* a = mec.makeForm("ErrForm", "tar");
			bur.signForm(*a);
			bur.executeForm(*a);
			delete a;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
