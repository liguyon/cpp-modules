#pragma once

#include <algorithm>
#include <iterator>


/**
 * Returns an iterator to the first occurence of elementToFind inside container,
 * or to the last element if there is no such iterator.
 * 
 * https://en.cppreference.com/w/cpp/algorithm/find
 * 
 */
template <typename T>
typename T::const_iterator easyfind(const T& container, int elementToFind)
{
	return std::find(container.begin(), container.end(), elementToFind);
}
