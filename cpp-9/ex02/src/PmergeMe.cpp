#include "PmergeMe.h"

#include <cstdlib>

#include <limits>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cassert>


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

static void insertVec(std::vector<int>& vec, int element)
{
	// lower_bound uses binary search
    std::vector<int>::iterator insertPosition = std::lower_bound(
		vec.begin(), vec.end(), element);
    vec.insert(insertPosition, element);
}

// naive implementation of https://en.wikipedia.org/wiki/Merge-insertion_sort
static void miSortVec(std::vector<int>& vec)
{
    size_t n = vec.size();

    if (n <= 1)
        return;

    std::vector<int> smaller, larger;
    for (size_t i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
        {
            if (vec[i] > vec[i + 1])
            {
                larger.push_back(vec[i]);
                smaller.push_back(vec[i + 1]);
            }
            else
            {
                larger.push_back(vec[i + 1]);
                smaller.push_back(vec[i]);
            }
        } 
        else
            larger.push_back(vec[i]);
    }
    miSortVec(larger);

    for (
		std::vector<int>::const_iterator it = smaller.begin();
		it != smaller.end();
		++it
	)
        insertVec(larger, *it);

    vec = larger;
}

static void insertLst(std::list<int>& lst, int element)
{
    // std::list<int>::iterator it = lst.begin();
    // while (it != lst.end() && *it < element)
    //     ++it;
    // lst.insert(it, element);

	// for some reason, the sort is 2 times slower using lower_bound ?
	std::list<int>::iterator insertPosition = std::lower_bound(
		lst.begin(), lst.end(), element);
    lst.insert(insertPosition, element);
}

static void miSortLst(std::list<int>& lst)
{
    int n = lst.size();

    if (n <= 1)
        return ;

    std::list<int> larger, smaller;
    std::list<int>::const_iterator it = lst.begin();
    
    while (it != lst.end())
	{
        int first = *it;
        ++it;
        if (it != lst.end())
		{
            int second = *it;
            ++it;
            if (first > second) {
                larger.push_back(first);
                smaller.push_back(second);
            }
			else
			{
                larger.push_back(second);
                smaller.push_back(first);
            }
        }
		else
            larger.push_back(first);
    }

    miSortLst(larger);

    for (
		std::list<int>::const_iterator it = smaller.begin();
		it != smaller.end();
		++it)
        insertLst(larger, *it);

    lst = larger;
}

template <typename T>
static bool isSorted(const T& seq) {
    if (seq.empty())
        return true;

    typename T::const_iterator it = seq.begin();
    typename T::const_iterator itNext = it;
    ++itNext;

    while (itNext != seq.end())
	{
        if (*it > *itNext)
            return false;
        ++it;
        ++itNext;
    }

    return true;
}

void PmergeMe::pmerge(int ac, char* av[])
{
	std::vector<int> sequence;
	if (!parseArgs(ac, av, sequence))
		return ;

	std::cout << std::fixed << std::setprecision(5);

	std::list<int> lst;
	Timer t;
	fillContainer(sequence, lst);
	miSortLst(lst);
	double elapsedLst = t.elapsed();

	std::vector<int> vec;
	t.reset();
	fillContainer(sequence, vec);
	miSortVec(vec);
	double elapsedVec = t.elapsed();

	// assert(isSorted(vec) == true);
	// assert(isSorted(lst));
	
	std::cout << "Before: ";
	printVec(sequence);
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
