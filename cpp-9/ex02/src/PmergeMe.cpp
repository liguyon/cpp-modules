#include "PmergeMe.h"

#include <cstdlib>

#include <limits>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>


static int parseInt(const char* cstr)
{
	const std::string str = cstr;

	if (str.length() < 1)
		throw "empty argument";
	if (str.length() > 11)
		throw "invalid integer";

	std::string::const_iterator it = str.begin();
	if (*it == '+')
		++it;
	for (; it != str.end(); ++it)
	{
		if (!std::isdigit(*it))
			throw "invalid integer";
	}

	long nbr = std::strtol(cstr, NULL, 10);
	if (nbr > std::numeric_limits<int>::max())
		throw "int overflow";

	return static_cast<int>(nbr);
}

static bool parseArgs(int ac, char* av[], std::vector<int>& sequence)
{
	for (int i = 0; i < ac; ++i)
	{
		try
		{
			int parsedInt = parseInt(av[i]);
			if (std::find(sequence.begin(), sequence.end(), parsedInt) != sequence.end())
				throw "dublicate";
			sequence.push_back(parsedInt);
		}
		catch(const char* e)
		{
			std::cerr << "error: " << e << " => " << av[i] << '\n';
			return false;
		}
	}
	return true;
}

template <typename T>
static void fillContainer(const std::vector<int>& src, T& container)
{
	for (
		std::vector<int>::const_iterator it = src.begin();
		it != src.end();
		++it)
		container.push_back(*it);
}

static void printVec(const std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		if (i < 5)
			std::cout << vec.at(i) << ' ';
		else
		{
			std::cout << "[...]";
			break ;
		}
	}
	std::cout << '\n';
}

static void printTimer(double elapsed, const char* containerName, size_t size)
{
	std::cout << "Time to process a range of " << size
		<< " elements with std::" << containerName
		<< " : " << elapsed * 1e6 << " us\n";
}

// static void miSortVector(std::vector<int>& vec)
// {

// }

// static void miSortList(std::list<int>& lst);

void PmergeMe::pmerge(int ac, char* av[])
{
	std::vector<int> sequence;
	if (!parseArgs(ac, av, sequence))
		return ;

	std::cout << std::fixed << std::setprecision(5);

	std::list<int> lst;
	Timer t;
	fillContainer(sequence, lst);
	// miSortList(lst);
	double elapsedLst = t.elapsed();

	std::vector<int> vec;
	t.reset();
	fillContainer(sequence, vec);
	// miSortVector(vec);
	double elapsedVec = t.elapsed();

	std::cout << "Before: ";
	printVec(vec);
	std::cout << "After:  ";
	printVec(vec);
	printTimer(elapsedVec, "vector", vec.size());
	printTimer(elapsedLst, "list  ", vec.size());
}

Timer::Timer()
{
	clock_gettime(CLOCK_MONOTONIC, &start_);
}

Timer::~Timer()
{
}

void Timer::reset()
{
	clock_gettime(CLOCK_MONOTONIC, &start_);
}

double Timer::elapsed() const
{
	struct timespec end;

	clock_gettime(CLOCK_MONOTONIC, &end);
	double elapsedTime;
	elapsedTime = (end.tv_sec - start_.tv_sec) * 1e9;
	elapsedTime = (elapsedTime + (end.tv_nsec - start_.tv_nsec)) * 1e-9;
	return elapsedTime;
}
