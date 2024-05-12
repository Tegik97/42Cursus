/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:09:11 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/12 20:36:39 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_search_min_max(int content, t_list *list)
{
	char	*minmax;
	int		diff;
	
	diff = 0;
	minmax = NULL;
	while (list)
	{
		if (list->content < content)
		{
			if ((content - list->content) < diff || diff == 0)
			{
				diff = content - list->content;
				free(minmax);
				minmax = ft_itoa(list->content);
			}
		}
		list = list->next;
	}
	return (minmax);
}

void	push_chunk_b(t_list **list_a, t_list **list_b, int size)
{
	while (ft_lstsize((*list_a)) > 3)
	{
		if ((*list_a)->content < (size / 4))
		{
			ft_push(list_a, list_b, 'b');
			(*list_b) = ft_rotate((*list_b), 'b');
		}
		else
			ft_push(list_a, list_b, 'b');
	}
}

t_list	*ft_sort_list(t_list *list_a, t_list *list_b)
{
	int	size;

	size = ft_lstsize(list_a);
	while (ft_lstsize(list_a) > ((size / 2)))
	{
		if (list_a->content < (size / 2) && list_a->content >= (size / 4))
		{
			ft_push(&list_a, &list_b, 'b');
			list_b = ft_rotate(list_b, 'b');
		}
		else if (list_a->content >= (size/2) && list_a->content < (size - (size / 4)))
			ft_push(&list_a, &list_b, 'b');
		else
			list_a = ft_rotate(list_a, 'a');
	}
	push_chunk_b(&list_a, &list_b, size);
	list_a = ft_sort_three(list_a);
	list_a = ft_sort_list_back(list_b, list_a);
	return (list_a);
}
