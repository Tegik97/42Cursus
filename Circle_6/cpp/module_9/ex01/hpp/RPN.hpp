/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:41:11 by mchiaram          #+#    #+#             */
/*   Updated: 2025/11/25 18:16:31 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <list>
# include <string>
# include <sstream>
# include <iostream>

class RPN
{
	private:
		std::list<int>	_operands;
	
	public:
		RPN();
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);
		~RPN();
		void	calculate(const std::string& expression);
};

#endif