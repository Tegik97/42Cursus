#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <stdexcept>
# include <string>
# include <fstream>
# include <map>

class BitcoinExchange
{
	private:
		const std::string	_filename;
		std::map			_dbValue;
		BitcoinExchange&	operator=(const BitcoinExchange& other);

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();

		int	openFile(const std::string& filename);
};

#endif