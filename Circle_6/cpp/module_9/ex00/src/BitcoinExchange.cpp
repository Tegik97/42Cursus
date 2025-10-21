#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& filename) : _filename(filename)
{
	if (filename.empty())
		throw std::invalid_argument("Error: Missing argument");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _filename(other._filename) {}

BitcoinExchange&	operator=(const BitcoinExchange& other)
{
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}