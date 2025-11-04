/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:41:17 by mchiaram          #+#    #+#             */
/*   Updated: 2025/11/04 15:41:18 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _operands(other._operands) {}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
		_operands = other._operands;
	return *this;
}

RPN::~RPN() {}

static int	getResult(int op1, int op2, char c)
{
	switch (c)
	{
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			if (op2 == 0)
				throw std::runtime_error("Error: division by zero");
			return op1 / op2;
		default:
			throw std::runtime_error("Error");
	}

}

static bool	toInt(const std::string& token, int& value)
{
	if (token.empty())
		return false;
	std::istringstream	iss(token);
	int					temp;
	
	if (!(iss >> temp) || !iss.eof())
		return false;
	
	value = temp;
	return true;
}

static bool	validOperator(const char& op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/')
		return true;

	std::cerr << "Error" << std::endl;
	return false;
}

void	RPN::calculate(const std::string& expression)
{
	if (expression.empty())
		std::cerr << "Error: bad argument" << std::endl;

	std::istringstream	iss(expression);
	int					value;

	try
	{
		std::string	token;
		while (iss >> token)
		{
			if (toInt(token, value))
				_operands.push(value);
			else
			{
				if (!validOperator(token[0]))
					return ;
				if (_operands.size() < 2)
				{
					std::cerr << "Error: not enough operands" << std::endl;
					return ;
				}
				int	op2 = _operands.top();
				_operands.pop();
				int op1 = _operands.top();
				_operands.pop();
				_operands.push(getResult(op1, op2, token[0]));
			}
		}
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << _operands.top() << std::endl;
}