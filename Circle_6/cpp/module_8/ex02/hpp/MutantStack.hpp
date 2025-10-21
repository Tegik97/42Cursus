/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:34:27 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/21 13:34:28 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator	iterator;

		iterator	begin() {return this->c.begin(); };
		iterator	end() { return this->c.end(); };

		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

		const_iterator	begin() const { return this->c.begin(); };
		const_iterator	end() const { return this->c.end(); };
};

#endif