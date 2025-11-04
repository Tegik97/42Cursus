/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:41:11 by mchiaram          #+#    #+#             */
/*   Updated: 2025/11/04 15:41:12 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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