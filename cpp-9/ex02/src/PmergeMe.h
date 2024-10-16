#pragma once

#include <sys/time.h>

#include <vector>
#include <list>


namespace PmergeMe
{
	void pmerge(int ac, char *av[]);
}

class Timer
{

public:
	Timer();
	~Timer();
	void	reset();
	// time elapsed since initialization or reset, in seconds
	double	elapsed() const; 

private:
	struct timespec start_;

	// we're not interested in copying
	Timer(const Timer& other);
	Timer& operator= (const Timer& other);

};
