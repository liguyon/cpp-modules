#include "whatever.h"
#include <iostream>
#include <cassert>
#include <string>

int main()
{
	{ // TEST: swap
        std::cout << "==== TESTS: swap (see asserts) ====\n";
		
		int a = 3;
		int b = 6;
		swap(a, b);
		assert(a == 6 && b == 3);

		std::string sa = "hello";
		std::string sb = "byebye";
		swap(sa, sb);
		assert(sa == "byebye" && sb == "hello");
		std::cout << "all tests passed" << std::endl;
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: min
        std::cout << "==== TESTS: min (see asserts) ====\n";
		
		int a = 3;
		int b = 6;
		assert(min(a, b) == a);

		unsigned int ua = 3;
		unsigned int ub = 6;
		assert(min(ua, ub) == ua);
		std::cout << "all tests passed" << std::endl;

	}

    std::cout << "\n================================================\n\n";

	{ // TEST: max
        std::cout << "==== TESTS: max (see asserts) ====\n";
		
		int a = 3;
		int b = 6;
		assert(max(a, b) == b);

		unsigned int ua = 3;
		unsigned int ub = 6;
		assert(max(ua, ub) == ub);
		std::cout << "all tests passed" << std::endl;
	}

	return 0;
}
