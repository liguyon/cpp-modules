#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>
#include <cassert>

int main()
{
	{ // TEST: basic tests
        std::cout << "==== TESTS: basic tests ====\n";
		Form a;
		std::cout << a << std::endl;

		Form b("42", 120, 2);
		std::cout << b << std::endl;

		Form c(b);
		std::cout << c << std::endl;

		Form d;
		d = b;
		std::cout << d << std::endl;
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: sign form
        std::cout << "==== TESTS: sign form ====\n";

		Form moneyGlitch("Form No. 1042-FG: Approval for Financial Grant to Lionel G.", 30, 70);

		Bureaucrat coffeeGuy("Jean Neymar", 149);
		coffeeGuy.signForm(moneyGlitch);
		assert(!moneyGlitch.isSigned());

		Bureaucrat cs("Davos guy", 1);
		cs.signForm(moneyGlitch);
		assert(moneyGlitch.isSigned());

		Bureaucrat pres("El Presidente", 27);
		pres.signForm(moneyGlitch);
		assert(moneyGlitch.isSigned());
	}

	return 0;
}
