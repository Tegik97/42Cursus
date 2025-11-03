#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <stdexcept>
# include <string>
# include <fstream>
# include <map>
# include <iostream>
# include <sstream>
# include <ctime>
# include <cctype>
# include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_dataValue;
		
		double	getClosestDate(const std::string& date) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		int		saveCSVData();
		int		printExchange(const std::string& filename);
};

#endif