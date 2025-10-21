#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

class BitcoinExchange
{
	private:
		const std::string	_filename;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		~BitcoinExchange();
};

#endif