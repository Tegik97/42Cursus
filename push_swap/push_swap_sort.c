/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:09:11 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/10 17:03:36 by mchiaram         ###   ########.fr       */
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
				minmax = ft_itoa(list->content);
			}
		}
		list = list->next;
	}
	return (minmax);
}

t_list	*ft_sort_list(t_list *list_a, t_list *list_b)
{
	ft_sort_sim(list_a, list_b);
	return (list_a);
}