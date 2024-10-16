#include <cassert>

#include <iostream>

#include "RPN.h"


int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "usage: ./RPN expression\n";
		return 0;
	}
	
	try
	{
		std::cout << RPN::compute(av[1]) << '\n';
	}
	catch(const char* e)
	{
		std::cerr << "Error: " << e << '\n';
	}

	return 0;
}


// TESTS
// int main()
// {
// 	// Test addition
// 	assert(RPN::compute("5 3 +") == 8);

// 	// Test subtraction
// 	assert(RPN::compute("7 3 -") == 4);

// 	// Test multiplication
// 	assert(RPN::compute("6 4 *") == 24);

// 	// Test division
// 	assert(RPN::compute("9 3 /") == 3);

// 	// Test mixed operations
// 	assert(RPN::compute("5 3 + 2 *") == 16);
// 	assert(RPN::compute("1 2 - 3 +") == 2);
// 	assert(RPN::compute("8 2 * 3 +") == 19);
// 	assert(RPN::compute("5 1 + 3 *") == 18);

// 	// Test zero operands
// 	assert(RPN::compute("0 0 +") == 0);
// 	assert(RPN::compute("0 0 -") == 0);
// 	assert(RPN::compute("0 0 *") == 0);
// 	try
// 	{
// 		assert(RPN::compute("0 0 /") == 0);
// 	}
// 	catch(const char* e)
// 	{
// 		std::cerr << e << '\n';
// 	}

// 	// Test single operand
// 	assert(RPN::compute("5") == 5);

// 	try
// 	{
// 		assert(RPN::compute("5 a +") == 0); // 'a' is not a valid character
// 	}
// 	catch(const char* e)
// 	{
// 		std::cerr << e << '\n';
// 	}

// 	try
// 	{
// 		assert(RPN::compute("5 3+") == 0); // Missing space
// 	}
// 	catch(const char* e)
// 	{
// 		std::cerr << e << '\n';
// 	}

// 	try
// 	{
// 		assert(RPN::compute("5  3 +") == 0); // Extra space after operand
// 	}
// 	catch(const char* e)
// 	{
// 		std::cerr << e << '\n';
// 	}
// }
