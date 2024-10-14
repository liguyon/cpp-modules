#include "Span.h"

#include <cmath>

#include <algorithm>


Span::Span()
{
}

Span::Span(unsigned int N)
	: m_capacity(N)
{
}

Span::Span(const Span& other)
{
	*this = other;
}

Span::~Span()
{
}

Span& Span::operator=(const Span& other)
{
	m_capacity = other.m_capacity;
	m_numbers.clear();
	std::vector<int>::const_iterator begin = other.m_numbers.begin();
	std::vector<int>::const_iterator end = other.m_numbers.end();
	for (std::vector<int>::const_iterator it = begin; it != end; ++it)
		m_numbers.push_back(*it);
	return *this;
}

void Span::addNumber(int nbr)
{
	if (m_numbers.size() >= m_capacity)
		throw MaximumCapacityException();
	m_numbers.push_back(nbr);
}

int Span::shortestSpan() const
{
	if (m_numbers.size() < 2)
		return 0;

	std::vector<int>::const_iterator tmp = m_numbers.begin();
	++tmp;
	std::vector<int>::const_iterator end = m_numbers.end();
	int currentShortest = std::abs(*tmp - *m_numbers.begin());
	for (std::vector<int>::const_iterator it = m_numbers.begin(); it != end; ++it)
	{
		int span = std::abs(*tmp - *it);
		if (span < currentShortest)
			currentShortest = span;
		++tmp;
	}
	return currentShortest;
}

int Span::longestSpan() const
{
	if (m_numbers.size() < 2)
		return 0;
	std::vector<int> copy = m_numbers;
	std::sort(copy.begin(), copy.end());
	return copy.back() - copy.front();
}

std::vector<int>::const_iterator Span::begin() const
{
	return m_numbers.begin();
}

std::vector<int>::const_iterator Span::end() const
{
	return m_numbers.end();
}
 
size_t Span::size() const
{
	return m_numbers.size();
}

const char* Span::MaximumCapacityException::what() const throw()
{
	return "Reached maximum capacity. Cannot add more elements.";
}
