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
//     assert(RPN::compute("9 2 /") == 4.5);
//     assert(RPN::compute("3 4 +") == 7);
//     assert(RPN::compute("7 3 -") == 4);
//     assert(RPN::compute("5 6 *") == 30);
//     assert(RPN::compute("8 2 /") == 4);
//     assert(RPN::compute("8 9 * 9 - 9 - 9 - 4 - 1 +") == 42);
//     assert(RPN::compute("5 1 2 + 4 * + 3 -") == 14);
//     assert(RPN::compute("6 2 3 + *") == 30);
//     assert(RPN::compute("9 3 /") == 3);
//     assert(RPN::compute("9 9 * 9 - 9 -") == 63);
//     assert(RPN::compute("9 1 1 1 1 + + + +") == 13);
//     assert(RPN::compute("2 3 + 4 5 * +") == 25);
//     assert(RPN::compute("3 4 -") == -1);
//     assert(RPN::compute("1 5 - 2 +") == -2);
//     assert(RPN::compute("1 2 + 3 4 + 5 6 + + +") == 21);
//     assert(RPN::compute("9 3 / 2 *") == 6);
//     assert(RPN::compute("6 2 * 3 /") == 4);
//     assert(RPN::compute("1 1 + 1 + 1 + 1 + 1 +") == 6);
//     assert(RPN::compute("2 2 * 2 * 2 *") == 16);
//     assert(RPN::compute("9 1 - 1 - 1 - 1 - 1 - 1 - 1 - 1 -") == 1);
//     assert(RPN::compute("1 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 +") == 10);
//     assert(RPN::compute("8 4 / 3 +") == 5);
//     assert(RPN::compute("2 3 * 5 -") == 1);
//     assert(RPN::compute("9 4 + 3 - 2 * 8 /") == 2.5);
//     assert(RPN::compute("5") == 5);   
//     assert(RPN::compute("5 3 +") == 8);
//     assert(RPN::compute("7 3 -") == 4);
//     assert(RPN::compute("6 4 *") == 24);
//     assert(RPN::compute("9 3 /") == 3);
//     assert(RPN::compute("5 3 + 2 *") == 16);
//     assert(RPN::compute("1 2 - 3 +") == 2);
//     assert(RPN::compute("8 2 * 3 +") == 19);
//     assert(RPN::compute("5 1 + 3 *") == 18);
//     assert(RPN::compute("8 9 * 9 - 9 - 9 - 4 - 1 +") == 42);
//     assert(RPN::compute("7 7 * 7 -") == 42);
//     assert(RPN::compute("1 2 * 2 / 2 * 2 4 - +") == 0);
//     assert(RPN::compute("0 0 +") == 0);
//     assert(RPN::compute("0 0 -") == 0);
//     assert(RPN::compute("0 0 *") == 0);
//     try
//     {
//         assert(RPN::compute("0 0 /") == 0);
//     }
//     catch(const char* e)
//     {
//         std::cerr << e << '\n';
//     }
//     try
//     {
//         assert(RPN::compute("5 a +") == 0); // 'a' is not a valid character
//     }
//     catch(const char* e)
//     {
//         std::cerr << e << '\n';
//     }
//     try
//     {
//         assert(RPN::compute("5 3+") == 0); // Missing space
//     }
//     catch(const char* e)
//     {
//         std::cerr << e << '\n';
//     }
//     try
//     {
//         assert(RPN::compute("5  3 +") == 0); // Extra space after operand
//     }
//     catch(const char* e)
//     {
//         std::cerr << e << '\n';
//     }
// }
