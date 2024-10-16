#pragma once

#include <map>
#include <string>



class BitcoinExchange
{

public:
	BitcoinExchange(const char* pathBtcDb);
	~BitcoinExchange();

	void lookup(const char* pathLookupDb) const;

private:
	typedef std::map<std::string, float> map;
	map db_;

	const std::string& getClosestDate(const std::string& date) const;

private:
	BitcoinExchange();

	// we don't want to copy, the exchange should be used as a singleton
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator= (const BitcoinExchange& other);
};
