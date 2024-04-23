/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:51:30 by mchiaram          #+#    #+#             */
/*   Updated: 2024/04/23 19:33:00 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "time.h"

t_list	*fill_list(t_list *list_a, char **elements);
void	print_list(t_list *list_a, t_list *list_b);
t_list	*ft_swap(t_list *list);
void	ft_push(t_list **list_src, t_list **list_dest);

#endif