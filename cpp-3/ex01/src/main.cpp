#include "ClapTrap.h"
#include "ScavTrap.h"
#include <iostream>
#include <cassert>

int main()
{
    { // TESTS: constructors, destructor, assignment operator
        std::cout << "==== TESTS: constructors, destructor, assignment operator ====\n";

        ScavTrap s0("scavy");
        assert(
            s0.getName() == std::string("scavy")
            && s0.getHealth() == 100
            && s0.getEnergy() == 50
            && s0.getAttack() == 20);
        
        ScavTrap s1(s0);
        assert(
            s1.getName() == std::string("scavy")
            && s1.getHealth() == 100
            && s1.getEnergy() == 50
            && s1.getAttack() == 20);
        
        ScavTrap s2;
        assert(
            s2.getName() == std::string("")
            && s2.getHealth() == 100
            && s2.getEnergy() == 50
            && s2.getAttack() == 20);
        s2 = s1;
        assert(s2.getName() == s1.getName());
    }

    std::cout << "\n================================================\n\n";

    { // TESTS: gameplay
        std::cout << "==== TESTS: gameplay ====\n";

        ScavTrap s0("scavy");
        s0.guardGate();
        assert(s0.getDefense() == 10 && s0.getEnergy() == 40);
        s0.guardGate();
        assert(s0.getDefense() == 10 && s0.getEnergy() == 40);
        s0.attack("victim");
        assert(s0.getEnergy() == 39);
        for (int i = 0; i < 9; ++i)
            s0.attack("victim");
        assert(s0.getEnergy() == 30);
        s0.takeDamage(11);
        assert(s0.getDefense() == 0 && s0.getHealth() == 99);
        s0.takeDamage(11);
        assert(s0.getHealth() == 99 - 11);
        s0.beRepaired(12);
        assert(s0.getHealth() == 99 - 11 + 12 && s0.getEnergy() == 29);
        s0.guardGate();
        assert(s0.getDefense() == 10 && s0.getEnergy() == 19);
        s0.takeDamage(9);
        assert(s0.getDefense() == 0 && s0.getHealth() == 100);
        s0.guardGate();
        assert(s0.getDefense() == 10 && s0.getEnergy() == 9);
        s0.takeDamage(109);
        assert(s0.getDefense() == 0 && s0.getHealth() == 1);
        s0.guardGate();
        assert(s0.getDefense() == 0 && s0.getEnergy() == 9);
        for (int i = 0; i < 9; ++i)
            s0.attack("victim");
        assert(s0.getEnergy() == 0);
        s0.attack("victim");
        s0.beRepaired(10);
        assert(s0.getEnergy() == 0);
        s0.takeDamage(1);
        assert(s0.getHealth() == 0);
        s0.takeDamage(1);
        assert(s0.getHealth() == 0);
        s0.attack("victim");
        s0.beRepaired(100);
        s0.guardGate();
    }

    std::cout << "\n================================================\n\n";

    return 0;
}
