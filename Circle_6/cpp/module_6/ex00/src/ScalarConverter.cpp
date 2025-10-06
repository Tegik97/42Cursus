#include "ScalarConverter.hpp"
#include <iomanip>

void	ScalarConverter::convert(const std::string& input)
{
	LiteralType	type = detectType(input);

	switch (type)
	{
		case CHAR_TYPE:
			convertFromChar(input);
			break;
		case INT_TYPE:
			convertFromInt(input);
			break;
		case FLOAT_TYPE:
			convertFromFloat(input);
			break;
		case DOUBLE_TYPE:
			convertFromDouble(input);
			break;
		case PSEUDO_LITERAL:
			convertFromPseudo(input);
			break;
		case ERROR_TYPE:
			std::cout << "Error: invalid input" << std::endl;
			break;
	}
}

ScalarConverter::LiteralType ScalarConverter::detectType(const std::string& input)
{
	if (input.empty())
		return ERROR_TYPE;

	if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
		return CHAR_TYPE;

	std::string	pseudoliteral[] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};
	for (int i = 0; i < 6; i++)
	{
		if (input == pseudoliteral[i])
			return PSEUDO_LITERAL;
	}

	return tryParseDetection(input);
}

ScalarConverter::LiteralType ScalarConverter::tryParseDetection(const std::string& input)
{
	char*	endptr;

	if (input.length() > 1 && input[input.length() - 1] == 'f')
	{
		std::string floatStr = input.substr(0, input.length() - 1);
		strtof(floatStr.c_str(), &endptr);
		if (*endptr == '\0')
			return FLOAT_TYPE;
	}

	long	longVal = strtol(input.c_str(), &endptr, 10);
	if (*endptr == '\0' && longVal >= INT_MIN && longVal <= INT_MAX)
		return INT_TYPE;

	strtod(input.c_str(), &endptr);
	if (*endptr == '\0')
		return DOUBLE_TYPE;
	
	return ERROR_TYPE;
}

void	ScalarConverter::convertFromChar(const std::string& input)
{
	char	c = input[0];

	std::cout << "char: '" << c << "'" << std::endl;

	int ascii = static_cast<int>(c);
	std::cout << "int: " << ascii << std::endl;

	std::cout << std::fixed << std::setprecision(2) << "float: " << static_cast<float>(ascii) << "f" << std::endl;

	std::cout << std::fixed << std::setprecision(2) << "double: " << static_cast<double>(ascii) << std::endl;
}

void	ScalarConverter::convertFromInt(const std::string& input)
{
	char*	endptr;
	int		value = strtol(input.c_str(), &endptr, 10);

	std::cout << "char: ";
	if (value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		char	c = static_cast<char>(value);
		if (isprint(c))
			std::cout <<"'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: " << value << std::endl;

	std::cout << std::fixed << std::setprecision(2) << "float: " << static_cast<float>(value) << "f" << std::endl;

	std::cout << std::fixed << std::setprecision(2) << "double: " << static_cast<double>(value) << std::endl;
}

void	ScalarConverter::convertFromFloat(const std::string& input)
{
	std::string	floatStr = input.substr(0, input.length() - 1);

	char	*endptr;
	float	value = strtof(floatStr.c_str(), &endptr);
	long	intValue = static_cast<long>(value);

	std::cout << "char: ";
	if (intValue < 0 || intValue > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		char	c = static_cast<char>(intValue);
		if (isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: ";
	if (intValue > INT_MAX || intValue < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << intValue << std::endl;

	std::cout << std::fixed << std::setprecision(2) << "float: " << value << "f" << std::endl;

	std::cout << std::fixed << std::setprecision(2) << "double: " << static_cast<double>(value) << std::endl;
}

void	ScalarConverter::convertFromDouble(const std::string& input)
{
	char*	endptr;
	double	value = strtod(input.c_str(), &endptr);
	long	intValue = static_cast<long>(value);

	std::cout << "char: ";
	if (intValue < 0 || intValue > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		char	c = static_cast<char>(intValue);
		if (isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: ";
	if (intValue > INT_MAX || intValue < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << intValue << std::endl;

	std::cout << std::fixed << std::setprecision(2) << "float: " << static_cast<float>(value) << "f" << std::endl;

	std::cout << std::fixed << std::setprecision(2) << "double: " << value << std::endl;
}

void	ScalarConverter::convertFromPseudo(const std::string& input)
{
	std::cout << "char: impossible" << std::endl;

	std::cout << "int: impossible" <<  std::endl;

	std::cout << "float: ";
	if (input == "nan" || input == "+inf" || input == "-inf")
		std::cout << input << "f" << std::endl;
	else
		std::cout << input << std::endl;

	std::cout << "double: ";
	if (input == "nanf" || input == "+inff" || input == "-inff")
		std::cout << input.substr(0, input.length() - 1) << std::endl;
	else
		std::cout << input << std::endl;
}
