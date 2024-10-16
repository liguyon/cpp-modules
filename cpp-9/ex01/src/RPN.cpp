#include "RPN.h"

#include <cstddef>
#include <iostream>

static const std::string allowedOperators = "+-*/";

double RPN::compute(const std::string& expression)
{
	std::queue<char> queue;
	try
	{
		parseInstructions(queue, expression);
	}
	catch(int e)
	{
		throw "invalid expression";
	}
	if (queue.empty())
		throw "empty expression";

	double result;
	char current = queue.front();
	queue.pop();
	if (!std::isdigit(current))
		throw "invalid operand";
	else
		result = current - '0';
	while (!queue.empty())
	{
		current = queue.front();
		queue.pop();
		if (queue.empty())
			throw "invalid expression";
		if (!std::isdigit(current))
			throw "invalid operand";
		int operand = current - '0';
		current = queue.front();
		queue.pop();
		switch (current)
		{
		case '+':
			result += operand;
			break ;
		case '-':
			result -= operand;
			break ;
		case '*':
			result *= operand;
			break ;
		case '/':
			if (!operand)
				throw "division by zero";
			result /= operand;
			break ;
		default:
			throw "invalid operator";
		}
	}

	return result;
}

void RPN::parseInstructions(std::queue<char>& queue, const std::string &expression)
{
	for (size_t i = 0; i < expression.length(); ++i)
	{
		if (i % 2 == 1)
		{
			if (expression[i] == ' ')
				continue ;
			else
				throw -1;
		}
		else
		{
			if (std::isdigit(expression[i])
			|| allowedOperators.find(expression[i]) != allowedOperators.npos)
				queue.push(expression[i]);
			else
				throw -1;
		}
	}
}
