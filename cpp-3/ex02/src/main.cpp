#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"
#include <iostream>
#include <cassert>

int main()
{
    { // TESTS: constructors, destructor, assignment operator
        std::cout << "==== TESTS: constructors, destructor, assignment operator ====\n";

        FragTrap f0("fragy");
        assert(
            f0.getName() == std::string("fragy")
            && f0.getHealth() == 100
            && f0.getEnergy() == 100
            && f0.getAttack() == 30);
        
        FragTrap f1(f0);
        assert(
            f1.getName() == std::string("fragy")
            && f1.getHealth() == 100
            && f1.getEnergy() == 100
            && f1.getAttack() == 30);
        
        FragTrap f2;
        assert(
            f2.getName() == std::string("")
            && f2.getHealth() == 100
            && f2.getEnergy() == 100
            && f2.getAttack() == 30);
        f2 = f1;
        assert(f2.getName() == f1.getName());
    }

    std::cout << "\n================================================\n\n";

    { // TESTS: gameplay
        std::cout << "==== TESTS: gameplay ====\n";

        FragTrap f0("fragy");
        f0.highFivesGuys();
        f0.takeDamage(99);
        assert(f0.getHealth() == 1);
        f0.beRepaired(1);
        assert(f0.getHealth() == 2 && f0.getEnergy() == 99);
        for (int i = 0; i < 99; ++i)
            f0.attack("victim");
        assert(f0.getEnergy() == 0);
        f0.attack("victim");
        f0.beRepaired(1);
        f0.takeDamage(3);
        assert(f0.getHealth() == -1);
        f0.highFivesGuys();
        f0.attack("victim");
        f0.beRepaired(1);
        f0.takeDamage(1000);
        assert(f0.getHealth() == -1);
    }

    return 0;
}
