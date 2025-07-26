/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:31:25 by mchiaram          #+#    #+#             */
/*   Updated: 2025/07/26 15:31:26 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public :
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap& other);
		~FragTrap();

		void	highFiveGuys();

};

#endif