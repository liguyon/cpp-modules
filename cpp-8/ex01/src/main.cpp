#include "Span.h"
#include <iostream>
#include <cassert>

int main()
{
	{ // TEST: basic tests
        std::cout << "==== TESTS: basic tests ====\n";
		Span s(3);
		try
		{
			s.addNumber(10);
			s.addNumber(10);
			s.addNumber(10);
			s.addNumber(10);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		assert(s.size() == 3);

		Span s1 = s;
		assert(s1.size() == 3);

		Span s2(3);
		s2.addNumber(1);
		Span s3 = s2;
		s3.addNumber(10);
		assert(s2.size() == 1);
		assert(s3.size() == 2);

		std::cout << "all tests passed\n";
	}

    std::cout << "\n================================================\n\n";

	{ // TEST: span
        std::cout << "==== TESTS: span ====\n";
		Span s(10);

		s.addNumber(20);
		s.addNumber(1);
		s.addNumber(3);
		s.addNumber(10);
		s.addNumber(10);
		s.addNumber(20);

		assert(s.longestSpan() == 19);
		assert(s.shortestSpan() == 0);

		Span s1(10);
		assert(s1.longestSpan() == 0);
		assert(s1.shortestSpan() == 0);
		s.addNumber(20);
		assert(s1.longestSpan() == 0);
		assert(s1.shortestSpan() == 0);
		
		std::cout << "all tests passed\n";
	}
	return 0;
}
