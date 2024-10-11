#pragma once

#include <cstddef>


template<typename T>
void iter(T arr[], size_t len, void (*fn)(const T&))
{
	for (size_t i = 0; i < len; ++i)
		fn(arr[i]);
}
