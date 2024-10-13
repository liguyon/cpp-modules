#include <ctime>
#include <cstdlib>

#include <iostream>

#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"


Base* generate()
{
	std::srand(std::time(0));
	int random = std::rand() % 3;

	switch (random)
	{
	case 0:
		return new A;
	case 1:
		return new B;
	case 2:
		return new C;
	default:
		return NULL;
	}
}

void identify(Base* p)
{
	std::cout << "identify(Base* p): ";
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	std::cout << std::endl;
}

void identify(Base& p)
{
	std::cout << "identify(Base& p): ";
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "A";
	}
	catch (std::exception & e) {}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "B";
	}
	catch (std::exception & e) {}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "C";
	}
	catch (std::exception & e) {}
	std::cout << std::endl;
}

int main()
{
	{ // TEST: leaks
        std::cout << "==== TESTS: inheritance leaks (run valgrind) ====\n";
		Base* base = new Base();
		A* a = new A();
		B* b = new B();
		C* c = new C();

		delete base;
		delete a;
		delete b;
		delete c;
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: dynamic_cast
        std::cout << "==== TESTS: dynamic cast ====\n";
		Base* random = generate();
		identify(random);
		identify(*random);
		delete random;
	}

	return 0;
}
