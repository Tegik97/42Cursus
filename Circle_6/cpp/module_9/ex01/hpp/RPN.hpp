#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <sstream>
# include <iostream>

class RPN
{
	private:
		std::stack<int>	_operands;
	
	public:
		RPN();
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);
		~RPN();
		void	calculate(const std::string& expression);
};

#endif