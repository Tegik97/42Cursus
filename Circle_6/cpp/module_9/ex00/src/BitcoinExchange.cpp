#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	saveCSVData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _dataValue(other._dataValue) {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_dataValue = other._dataValue;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

int	BitcoinExchange::saveCSVData()
{
	std::ifstream	csvFile("data.csv");
	if (!csvFile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 0;
	}

	std::string		line;

	if (!std::getline(csvFile, line))
	{
		std::cerr << "Error: empty file" << std::endl;
		return 0;
	}

	while (std::getline(csvFile, line))
	{
		if (line.empty())
			continue ;

		std::istringstream	iss(line);
		std::string			date;
		std::string			valueStr;

		if (std::getline(iss, date, ',') && std::getline(iss, valueStr))
		{
			std::stringstream ss(valueStr);
			double	value;
			if (ss >> value)
				_dataValue[date] = value;
			else
				std::cerr << "Error: invalid value in line: " << line << std::endl;
		}
		else
			std::cerr << "Error: bad line format: " << line << std::endl;
	}
	return 1;
}

static std::string	trim(const std::string& str)
{
	std::size_t	start = str.find_first_not_of(" ");
	if (start == std::string::npos)
		return "";

	std::size_t end = str.find_last_not_of(" ");
	return str.substr(start, end - start + 1);	
}

static bool	isValidDateFormat(const std::string& date)
{
	if (date.length() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (std::size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}
	
	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1000 || year > 9999)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		return false;

	return true;
}

static bool	isDateNotInFuture(const std::string& date)
{
	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	std::time_t	now = std::time(NULL);
	std::tm*	today = std::localtime(&now);
	if (today == NULL)
	{
		std::cerr << "Error: could not get current time" << std::endl;
		return false;
	}

	int	currentYear = today->tm_year + 1900;
	int	currentMonth = today->tm_mon + 1;
	int	currentDay = today->tm_mday;

	if (year > currentYear)
		return false;
	if (year == currentYear && month > currentMonth)
		return false;
	if (year == currentYear && month == currentMonth && day > currentDay)
		return false;

	return true;
}

static int	parseData(const std::string& line, std::string& date, double& nCoins)
{
	std::istringstream	iss(line);
	std::string			dateStr;
	std::string			valueStr;

	if (!std::getline(iss, dateStr, '|') || !std::getline(iss, valueStr))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}

	dateStr = trim(dateStr);
	valueStr = trim(valueStr);

	if (dateStr.empty() || valueStr.empty())
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}

	if (!isValidDateFormat(dateStr))
	{
		std::cerr << "Error: invalid date format => " << dateStr << std::endl;
		return 0;
	}

	if (!isDateNotInFuture(dateStr))
	{
		std::cerr << "Error: date is in the future => " << dateStr << std::endl;
		return 0;
	}

	std::stringstream	ss(valueStr);
	double				value;
	if (!(ss >> value))
	{
		std::cerr << "Error: invalid number => " << valueStr << std::endl;
		return 0;
	}

	if (value < 0)
	{
		std::cerr << "Error: not a positive number" << std::endl;
		return 0;
	}

	if (value > 1000)
	{
		std::cerr << "Error: too large a number" << std::endl;
		return 0;
	}

	date = dateStr;
	nCoins = value;

	return 1;
}

double	BitcoinExchange::getClosestDate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _dataValue.find(date);

	if (it != _dataValue.end())
		return it->second;

	it = _dataValue.lower_bound(date);
	if (it == _dataValue.begin())
	{
		std::cerr << "Error: no data available before date => " << date << std::endl;
		return -1;
	}

	--it;
	return it->second;
}

int	BitcoinExchange::printExchange(const std::string& filename)
{
	if (_dataValue.empty())
	{
		std::cerr << "Error: no exchange rate data available" << std::endl;
		return 0;
	}

	std::ifstream	inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 0;
	}

	std::string	line;

	if (!std::getline(inputFile, line))
	{
		std::cerr << "Error: empty file" << std::endl;
		return 0;
	}

	while (std::getline(inputFile, line))
	{
		if (line.empty())
			continue ;

		std::string	date;
		double		nCoins;

		if (!parseData(line, date, nCoins))
			continue ;

		double	exchangeRate = getClosestDate(date);
		if (exchangeRate < 0)
			continue ;
		double	result = nCoins * exchangeRate;
		std::cout << date << " => " << nCoins << " = " << result << std::endl;
	}
	return 1;
}