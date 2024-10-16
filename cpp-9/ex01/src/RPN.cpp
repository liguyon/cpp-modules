#include "RPN.h"

#include <cstddef>

#include <stack>


static const std::string allowedOperators = "+-*/";

static bool checkExpression(const std::string &expression)
{
	if (!expression.length())
		return false;
	int countOperands = 0;
	int countOperators = 0;
	for (size_t i = 0; i < expression.length(); ++i)
	{
		if (i % 2)
		{
			if (expression[i] != ' ')
				return false;
		}
		else
		{
			if (std::isdigit(expression[i]))
				++countOperands;
			else if (allowedOperators.find(expression[i]) != allowedOperators.npos)
				++countOperators;
			else
				return false;
		}
	}
	if (countOperands < 1)
		return false;
	return countOperands == countOperators + 1;
}

double RPN::compute(const std::string& expression)
{
	std::stack<double> operands;

	if (!checkExpression(expression))
		throw "invalid expression";

	for (
		std::string::const_iterator it = expression.begin();
		it != expression.end();
		++it)
	{
		if (std::isdigit(*it))
			operands.push(*it - '0');
		else if (*it == ' ')
			continue ;
		else
		{
			double y = operands.top();
			operands.pop();
			double x = operands.top();
			operands.pop();
			switch (*it)
			{
			case '+':
				operands.push(x + y);
				break ;
			case '-':
				operands.push(x - y);
				break ;
			case '*':
				operands.push(x * y);
				break ;
			case '/':
				if (!y)
					throw "division by zero";
				operands.push(x / y);
				break ;
			}
		}
	}
	return operands.top();
}
