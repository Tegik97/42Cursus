/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:06:14 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/09 14:16:30 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <stdexcept>
# include <string>

template<typename T>
int	easyfind(T& cont, int find)
{
	for (typename T::iterator it = cont.begin(); it != cont.end(); ++it)
	{
		if (*it == find)
			return *it;
	}
	throw std::runtime_error("Value " + std::to_string(find) + " not found in container");
}

#endif