/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:04:44 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/13 19:12:26 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_sort_index(t_list *list, size_t i)
{
	if (ft_lstsize(list) == 3)
	{
		if (i == 0)
			list = ft_rotate(list, 'a');
		else if (i == 1)
			list = ft_reverse_rotate(list, 'a');
	}
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

int	ft_check_list_sorted(t_list **list)
{
	size_t	size;
	t_list	*current;

	size = ft_lstsize(*list);
	if (size <= 3)
		*list = ft_sort_three(*list);
	current = *list;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
