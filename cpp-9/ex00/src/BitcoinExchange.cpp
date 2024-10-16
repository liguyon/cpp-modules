#include "BitcoinExchange.h"

#include <cstdlib>

#include <fstream>
#include <iostream>
#include <exception>
#include <algorithm>


static void parseCsvLine(
	const std::string& line, std::string& date, float& value);
static void parseLookupDbLine(
	const std::string& line, std::string& date, float& value);
static void parseDate(const std::string& raw, std::string& out);
static void parseAmount(const std::string& raw, float& out);


BitcoinExchange::BitcoinExchange(const char* pathBtcDb)
{
	std::ifstream inf(pathBtcDb);
	if (!inf)
		throw "Could not open database " + std::string(pathBtcDb);

	std::string str;
	inf >> str;
	while (inf >> str)
	{
		std::string date;
		float value;
		parseCsvLine(str, date, value);
		db_.insert(std::pair<std::string, float>(date, value));
	}
	std::cout << "Database successfully loaded. Loaded "
		<< db_.size() << " records.\n\n";
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::lookup(const char* pathLookupDb) const
{	
	std::ifstream inf(pathLookupDb);
	if (!inf)
		throw "Could not open lookup file " + std::string(pathLookupDb);
	std::string str;
	int line = 0;
	std::getline(inf, str);
	++line;
	if (str.compare("date | value") != 0)
		throw std::string("Invalid input file header.");
	while (std::getline(inf, str))
	{
		++line;
		try
		{
			std::string date;
			float amount;
			parseLookupDbLine(str, date, amount);
			if (db_.count(date))
			{
				std::cout << date << " => " << amount
					<< " = "<< amount * db_.at(date) << "\n";
			}
			else
			{
				std::string closestDate = getClosestDate(date);
				std::cout << date << " (lookup: " << closestDate << ") => "
					<< amount << " = "<< amount * db_.at(closestDate) << "\n";
			}
		}
		catch(const std::string& e)
		{
			std::cerr << pathLookupDb << ":" << line << ": error: " << e << "\n";
			continue ;
		}
	}
}

const std::string& BitcoinExchange::getClosestDate(const std::string& date) const
{
	const char* cdate = date.c_str();
	for (map::const_reverse_iterator it = db_.rbegin(); it != db_.rend(); ++it)
	{
		if (it->first.compare(cdate) < 0)
			return (it->first);
	}
	return (db_.begin()->first);
}

static void parseCsvLine(const std::string& line, std::string& date, float& value)
{
	size_t i = 0;
	for (; i < line.length(); ++i)
	{
		if (line.at(i) == ',')
			break ;
	}
	date = line.substr(0, i);
	value = std::strtof(line.substr(i + 1).c_str(), NULL);
}

static void parseLookupDbLine(
	const std::string& line, std::string& date, float& value)
{
	size_t sepPos = line.find('|');
	if (sepPos == line.npos || sepPos != 11)
		throw "bad input => " + line;
	std::string left = line.substr(0, sepPos);
	std::string right = line.substr(sepPos + 1);

	try
	{
		parseDate(left, date);
		parseAmount(right, value);
	}
	catch(const std::string& e)
	{
		throw e + " => " + line;
	}
}

// can't use C++11 enum class
namespace Date
{
	enum ParserState
	{
		start,
		year,
		month,
		day,
		sep,
	};
}

static void parseDate(const std::string& raw, std::string& out)
{
	int y, m, d = 0;
	Date::ParserState state = Date::start;
	for (size_t i = 0; i < raw.length(); ++i)
	{
		switch (state)
		{
		case Date::start:
			if (std::isdigit(raw[i]))
				state = Date::year;
			else
				throw std::string("invalid date");
			break;
		case Date::year:
			if (std::isdigit(raw[i]) && i <= 3)
			{
				if (i == 3)
					y = static_cast<int>(std::strtol(raw.substr(0, 4).c_str(), NULL, 10));
			}
			else if (i == 4 && raw[i] == '-')
				state = Date::sep;
			else
				throw std::string("invalid date");
			break ;
		case Date::sep:
			if (std::isdigit(raw[i]) && i == 5)
				state = Date::month;
			else if (std::isdigit(raw[i]) && i == 8)
				state = Date::day;
			else
				throw std::string("invalid date");
			break ;
		case Date::month:
			if (std::isdigit(raw[i]) && i == 6)
				m = static_cast<int>(std::strtol(raw.substr(5, 2).c_str(), NULL, 10));
			else if (i == 7 && raw[i] == '-')
				state = Date::sep;
			else
				throw std::string("invalid date");
			break ;
		case Date::day:
			if (std::isdigit(raw[i]) && i == 9)
				d = static_cast<int>(std::strtol(raw.substr(8, 2).c_str(), NULL, 10));
			else if (i == 10 && !(raw[i] == ' '))
				throw std::string("invalid date");
			break ;
		}
	}
	if ((y == 2009 && m == 1 && d < 3) || y < 2009)
		throw std::string("Bitcoin was launched on 3 January 2009");
	if (!(m >= 1 && m <= 12))
		throw std::string("invalid month");
	if (!(d >= 1 && d <= 31))
		throw std::string("invalid day");
	out = raw.substr(0, 10);
}

// can't use C++11 enum class
namespace Float
{
	enum ParserState
	{
		start,
		sign,
		whole,
		dot,
		fractional,
	};
}

static void parseAmount(const std::string& raw, float& out)
{
	Float::ParserState state = Float::start;
	std::string::const_iterator it = raw.begin();
	if (*it != ' ')
		throw std::string("invalid amount");
	++it;
	for (; it != raw.end(); ++it)
	{
		switch (state)
		{
		case Float::start:
			if (*it == '+')
				state = Float::sign;
			else if (std::isdigit(*it))
				state = Float::whole;
			else if (*it == '-')
				throw std::string("amount must be positive");
			else
				throw std::string("invalid amount");
			break;
		case Float::sign:
			if (std::isdigit(*it))
				state = Float::whole;
			else
				throw std::string("invalid amount");
			break;
		case Float::whole:
			if (std::isdigit(*it))
				continue ;
			else if (*it == '.')
				state = Float::dot;
			else
				throw std::string("invalid amount");
			break;
		case Float::dot:
			if (std::isdigit(*it))
				state = Float::fractional;
			else
				throw std::string("invalid amount");
			break;
		case Float::fractional:
			if (std::isdigit(*it))
				continue ;
			else
				throw std::string("invalid amount");
			break;
		}
	}
	out = std::strtof(raw.substr(1).c_str(), NULL);
	if (out > 1000)
		throw std::string("amount too high");
}
