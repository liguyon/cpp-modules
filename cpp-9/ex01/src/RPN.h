#pragma once

#include <queue>
#include <string>


class RPN
{

public:
	static double compute(const std::string& expression);

private:
	RPN();

	static void parseInstructions(
		std::queue<char>& queue, const std::string& expression);

};
