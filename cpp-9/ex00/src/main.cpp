#include <iostream>
#include <string>

#include "BitcoinExchange.h"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "usage: ./btc input.txt\n";
		return 0;
	}
	
	try
	{
		BitcoinExchange exchange("data.csv");
		exchange.lookup(av[1]);
	}
	catch(const std::string& e)
	{
		std::cerr << e << '\n';
	}

	return 0;
}
