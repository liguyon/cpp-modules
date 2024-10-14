#pragma once

#include <vector>
#include <exception>
#include <cstddef>


class Span
{

public:
	class MaximumCapacityException : public std::exception {
	public:
		virtual const char* what() const throw ();
	};

public:
	Span(unsigned int N);
	Span(const Span& other);
	~Span();

	Span& operator= (const Span& other);

	void	addNumber(int nbr);
	int		shortestSpan() const;
	int		longestSpan() const;

	std::vector<int>::const_iterator begin() const;
	std::vector<int>::const_iterator end() const;
	size_t size() const;

private:
	Span();

	std::vector<int> 	m_numbers;
	size_t				m_capacity;
};
