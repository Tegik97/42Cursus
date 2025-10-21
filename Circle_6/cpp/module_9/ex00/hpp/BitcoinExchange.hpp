#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <stdexcept>
# include <string>
# include <vector>

class BitcoinExchange
{
	private:
		const std::string	_filename;
		BitcoinExchange&	operator=(const BitcoinExchange& other);

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();
};

#endif