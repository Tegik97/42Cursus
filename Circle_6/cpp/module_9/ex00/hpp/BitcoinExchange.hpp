/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:46:47 by mchiaram          #+#    #+#             */
/*   Updated: 2025/11/04 12:46:48 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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