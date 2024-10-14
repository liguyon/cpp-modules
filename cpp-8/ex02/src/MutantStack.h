#pragma once

#include <stack>
#include <deque>


template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

public:
	MutantStack() {}
	MutantStack(const MutantStack& other) { *this = other; }
	~MutantStack() {}

	MutantStack& operator=(const MutantStack& other)
	{
		std::stack<T,Container>::operator=(other);
		return *this;
	}

	typedef typename Container::iterator iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	typedef typename Container::const_iterator const_iterator;
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }


};
