#pragma once

#include <cstddef>
#include <exception>

template <typename T>
class Array
{

public:
	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char* what() const throw ()
		{
			return "trying to access an element out of bounds";
		}
	};

public:
	Array() { m_data = NULL; m_length = 0; }

	Array(unsigned int n)
		: m_data(new T[n]), m_length(n)
	{
		for (size_t i = 0; i < n; ++i)
			m_data[i] = T();
	}

	Array(const Array& other)
		: m_data(new T[other.size()]), m_length(other.m_length)
	{
		*this = other;
	}

	~Array() { delete[] m_data; }
	
	Array& operator= (const Array& other)
	{
		if (this == &other)
			return *this;
		delete[] m_data;
		m_length = other.m_length;
		m_data = new T[other.m_length];
		for (size_t i = 0; i < other.m_length; ++i)
			m_data[i] = other.m_data[i];
		return *this;
	}

	T& operator[] (size_t index) const
	{
		if (index >= m_length)
			throw OutOfBoundsException();
		return m_data[index];
	}

	size_t size() const { return m_length; }


private:
	T*		m_data;
	size_t	m_length;
};
