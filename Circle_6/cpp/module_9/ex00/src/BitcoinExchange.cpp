#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& filename) : _filename(filename)
{
	if (!openFile)
		throw std::invalid_argument("Error: Missing argument");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _filename(other._filename) {}

BitcoinExchange&	operator=(const BitcoinExchange& other)
{
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

int	BitcoinExchange::openFile(const std::string& filename)
{
	std::ifstream file(filename)
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 0;
	}
}