#include "ClapTrap.h"
#include <iostream>


int main()
{
    { // TESTS: constructors, destructor, assignment operator
        std::cout << "==== TESTS: constructors, destructor, assignment operator ====\n";
        ClapTrap c0("c0");
        std::cout << &c0 << "\n\n";

        ClapTrap c1(c0);
        std::cout << &c1 << "\n\n";

        ClapTrap c2("c2");
        c2 = c1;
    }

    std::cout << "\n================================================\n\n";

    { // TESTS: energy
        std::cout << "==== TESTS: energy ====\n";
        ClapTrap clappy("clappy");
        std::cout << "\n";
        for (int i = 0; i <= 10; ++i)
            clappy.attack("victim");
        clappy.beRepaired(100);
        std::cout << "\n";
    }

    std::cout << "\n================================================\n\n";

    { // TESTS: health
        std::cout << "==== TESTS: health ====\n";
        ClapTrap clapybara("clapybara");
        std::cout << "\n";
        clapybara.takeDamage(1);
        clapybara.takeDamage(5);
        clapybara.beRepaired(6);
        clapybara.takeDamage(2147483648);
        clapybara.attack("no one because clapybara is chill");
        clapybara.beRepaired(100);
        std::cout << "\n";
    }

    return 0;
}
