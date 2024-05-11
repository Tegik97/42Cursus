/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:09:11 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/11 19:32:37 by mchiaram         ###   ########.fr       */
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

static void	ft_do_r(t_list **list_a, t_list **list_b, char *minmax, int target, size_t size)
{
	size_t	index_a;
	size_t	index_b;
	size_t	size_b;

	size_b = ft_lstsize((*list_b));
	index_a = ft_find_index((*list_a), target);
	index_b = 0;
	if (minmax)
		index_b = ft_find_index((*list_b), ft_atoi(minmax));
	while ((*list_a)->content != target || (minmax && (*list_b)->content != ft_atoi(minmax)))
	{
		if ((*list_a)->content != target && index_a <= (size/2)
			&& index_a != 0)
			(*list_a) = ft_rotate((*list_a), 'a');
		else if ((*list_a)->content != target && index_a > (size/2)
				&& index_a != 0)
			(*list_a) = ft_reverse_rotate((*list_a), 'a');
		else if (minmax && ((*list_b)->content != ft_atoi(minmax)
			&& index_b <= (size_b/2)))
			(*list_b) = ft_rotate((*list_b), 'b');
		else if (minmax && ((*list_b)->content != ft_atoi(minmax)
			&& index_b > (size_b/2)))
			(*list_b) = ft_reverse_rotate((*list_b), 'b');
	}
}

static void	ft_do_rr(t_list **list_a, t_list **list_b, char *minmax, int target, size_t size)
{
	size_t	index_a;
	size_t	index_b;
	size_t	size_b;
	
	size_b = ft_lstsize((*list_b));
	index_a = ft_find_index((*list_a), target);
	index_b = ft_find_index((*list_b), ft_atoi(minmax));
	while ((*list_a)->content != target && (*list_b)->content != ft_atoi(minmax))
	{
		if ((index_a > (size/2) && index_b > (size_b/2))
		|| ((index_a > (size/2) && (index_b + 1) == size_b)))
		{
			(*list_a) = ft_reverse_rotate((*list_a), '0');
			(*list_b) = ft_reverse_rotate((*list_b), 'r');
		} 
		else if (index_a <= (size/2) && index_b <= (size_b/2))
		{
			(*list_a) = ft_rotate((*list_a), '0');
			(*list_b) = ft_rotate((*list_b), 'r');
		}
	}
}

t_list	*ft_sort_list(t_list *list_a, t_list *list_b)
{
	int		bestnum;
	char	*minmax;
	size_t	size_a;
	
	minmax = NULL;
	size_a = ft_lstsize(list_a);
	print_list(list_a, list_b);
	while (ft_lstsize(list_a) > 3)
	{
		bestnum = ft_sort_sim(list_a, list_b);
		minmax = ft_search_min_max(bestnum, list_b);
		if (minmax)
			ft_do_rr(&list_a, &list_b, minmax, bestnum, size_a);
		ft_do_r(&list_a, &list_b, minmax, bestnum, size_a);
		ft_push(&list_a, &list_b, 'b');
		print_list(list_a, list_b);
	}
	list_a = ft_sort_three(list_a);
	return (list_a);
}