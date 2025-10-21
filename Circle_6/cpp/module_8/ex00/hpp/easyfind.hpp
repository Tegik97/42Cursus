/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:06:14 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/21 13:33:50 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <stdexcept>

template<typename T>
typename T::iterator	easyfind(T& cont, int find)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), find);
	if (it == cont.end())
		throw std::runtime_error("Value not found in container");
	return it;
}

#endif