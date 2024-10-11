#include "iter.h"
#include <iostream>
#include <cassert>


static void printSquare(const int& x)
{
	std::cout << x * x << std::endl;
}

static void agaga(const bool& isAgaga)
{
	std::cout << (isAgaga ? "agaga" : "I think, therefore I am.") << std:: endl;
}

int main()
{
	{ // TEST: int array
        std::cout << "==== TESTS: iter int array ====\n";
		
		int arr[] = {1, 2, 4, 5, 9, 10};
		iter(arr, sizeof arr / sizeof *arr, printSquare);
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: string array
        std::cout << "==== TESTS: iter bool array ====\n";
		
		bool arr[] = {true, true, false, true};
		iter(arr, sizeof arr, agaga);
	}

	return 0;
}
