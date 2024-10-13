#include "ScalarConverter.h"
#include <iostream>
#include <limits>
#include <cstdlib>

enum ScalarType
{
	tChar,
	tInt,
	tFloat,
	tDouble,
	inf,
	nan,
	undefined,
};

enum ParserState
{
	start,
	sign,
	whole,
	dot,
	fractional,
};

static ScalarType parse(const std::string& literal)
{
	ParserState state = start;
	for (size_t i = 0; i < literal.length(); ++i)
	{
		switch (state)
		{
		case start:
			if (literal[i] == '+' || literal[i] == '-')
				state = sign;
			else if (literal[i] == '.')
				state = dot;
			else if (std::isdigit(literal[i]))
				state = whole;
			else if (literal.length() == 1)
				return tChar;
			else if (!literal.compare("nan") || !literal.compare("nanf"))
				return nan;
			else if (!literal.compare("inf") || !literal.compare("inff"))
				return inf;
			else
				return undefined;
			break;
		case sign:
			if (std::isdigit(literal[i]))
				state = whole;
			else if (literal[i] == '.')
				state = dot;
			else if (!literal.substr(i).compare("inf") || !literal.substr(i).compare("inff"))
				return inf;
			else
				return undefined;
			break;
		case whole:
			if (std::isdigit(literal[i]))
				continue ;
			else if (literal[i] == '.')
				state = dot;
			else if (!literal.substr(i).compare("f"))
				return tFloat;
			else
				return undefined;
			break;
		case dot:
			if (std::isdigit(literal[i]))
				state = fractional;
			else if (
				!literal.substr(i).compare("f")
				&& literal.length() >= 3
				&& std::isdigit(literal[i - 2])
			)
				return tFloat;
			else
				return undefined;
			break;
		case fractional:
			if (std::isdigit(literal[i]))
				continue ;
			else if (!literal.substr(i).compare("f"))
				return tFloat;
			else
				return undefined;
			break;
		}
	}
	switch (state)
	{
	case dot:
		return tDouble;
	case fractional:
		return tDouble;
	case whole:
		return tInt;
	default:
		return undefined;
	}
}

static void printChar(char c, bool canConvert)
{
	std::cout << "char: ";
	if (!canConvert)
		std::cout << "impossible";
	else if (!std::isprint(c))
		std::cout << "non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << "\n";
}

template <typename T>
static void printNum(T num, const std::string& typeName,
	bool canConvert=true, bool isNan=false, bool isInf=false, bool isNeg=false)
{
	std::cout << typeName << ": ";
	if (!canConvert)
		std::cout << "impossible";
	else if (isNan)
		std::cout << "nan";
	else if (isInf)
	{
		if (isNeg)
			std::cout << "-";
		std::cout << "inf";
	}
	else
		std::cout << num;
	if (canConvert && !typeName.compare("float"))
		std::cout << "f";
	std::cout << "\n";
}

void ScalarConverter::convert(const std::string& literal)
{
	char 	c;
	int		i;
	float	f;
	double	d;
	switch (parse(literal))
	{
	case tChar:
		c = literal[0];
		printChar(c, true);
		printNum(static_cast<int>(c), "int");
		printNum(static_cast<float>(c), "float");
		printNum(static_cast<double>(c), "double");
		break;
	case tInt:
		i = std::strtol(literal.c_str(), NULL, 10);
		if (i < 0 || i > 127)
			printChar(0, false);
		else
			printChar(static_cast<char>(i), true);
		printNum(i, "int");
		printNum(static_cast<float>(i), "float");
		printNum(static_cast<double>(i), "double");
		break;
	case tFloat:
		f = std::strtof(literal.c_str(), NULL);
		if (f < 0 || f > 127)
			printChar(0, false);
		else
			printChar(static_cast<char>(f), true);
		if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
			printNum(0, "int", false);
		else
			printNum(static_cast<int>(f), "int");
		printNum(f, "float");
		printNum(static_cast<double>(f), "double");
		break;
	case tDouble:
		d = std::strtod(literal.c_str(), NULL);
		if (d < 0 || d > 127)
			printChar(0, false);
		else
			printChar(static_cast<char>(d), true);
		if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
			printNum(0, "int", false);
		else
			printNum(static_cast<int>(d), "int");
		if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
			printNum(0, "float", false);
		else
			printNum(static_cast<float>(d), "float");
		printNum(d, "double");
		break;
	case nan:
		printChar(0, false);
		printNum(0, "int", false);
		printNum(0, "float", true, true);
		printNum(0, "double", true, true);
		break;
	case inf:
		printChar(0, false);
		printNum(0, "int", false);
		printNum(0, "float", true, false, true, literal[0] == '-');
		printNum(0, "double", true, false, true, literal[0] == '-');
		break;
	default:
		printChar(0, false);
		printNum(0, "int", false);
		printNum(0, "float", false);
		printNum(0, "double", false);
		break;
	}
}
