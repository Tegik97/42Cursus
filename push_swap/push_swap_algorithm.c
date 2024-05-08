/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:04:44 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/08 18:03:00 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static t_list	*ft_sort_index(t_list *list, size_t i)
{
	if (i == 0)
		list = ft_rotate(list, 'a');
	else if (i == 1)
		list = ft_reverse_rotate(list, 'a');
	if (list->content > list->next->content)
		list = ft_swap(list, 'a');
	return (list);
}
t_list	*ft_sort_three(t_list *list)
{
	t_list	*current;
	int		max;
	size_t	i;

	current = list;
	i = 0;
	max = current->content;
	while (current)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	current = list;
	while (current->content != max)
	{
		i++;
		current = current->next;
	}
	list = ft_sort_index(list, i);
	return (list);
}
static t_list	*ft_sort(t_list *list)
{
	if (ft_lstsize(list) < 4)
		list = ft_sort_three(list);
	return (list);
}
t_list	*ft_check_list(t_list *list)
{
	t_list	*current;

	current = list;
	while (current->next)
	{
		if (current->content > current->next->content)
		{
			list = ft_sort(list);
			break ;
		}
		current = current->next;
	}
	return (list);
}