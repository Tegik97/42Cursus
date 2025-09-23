#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <climits>
# include <cstdlib>
# include <cctype>
# include <iostream>

class ScalarConverter
{
	private:
		enum LiteralType {
			CHAR_TYPE,
			INT_TYPE,
			FLOAT_TYPE,
			DOUBLE_TYPE,
			PSEUDO_LITERAL,
			ERROR_TYPE
		};
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
		static LiteralType	detectType(const std::string& input);
		static LiteralType	tryParseDetection(const std::string& input);
		static void			convertFromChar(const std::string& input);
		static void			convertFromInt(const std::string& input);
		static void			convertFromFloat(const std::string& input);
		static void			convertFromDouble(const std::string& input);
		static void			convertFromPseudo(const std::string& input);

		public:
			static void	convert(const std::string& input);
};

#endif