/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:09:11 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/12 20:22:26 by menny            ###   ########.fr       */
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
				&& index_a != size)
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
		else
			break ;
	}
}

static t_list	*sort_list_b(t_list *list_b, size_t size)
{
	t_list	*current;
	int		max;
	size_t index;
	
	max = INT_MIN;
	current = list_b;
	while (current)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	index = ft_find_index(list_b, max);
	while (list_b->content != max)
	{
		if (index > (size/2) || index == (size - 1))
			list_b = ft_reverse_rotate(list_b, 'b');
		else
			list_b = ft_rotate(list_b, 'b');
	}
	return (list_b);
}

t_list	*ft_sort_list(t_list *list_a, t_list *list_b)
{
	int		bestnum;
	char	*minmax;
	size_t	size_a;
	
	minmax = NULL;
	while (ft_lstsize(list_a) > 3)
	{
		size_a = ft_lstsize(list_a);
		bestnum = ft_sort_sim(list_a, list_b);
		minmax = ft_search_min_max(bestnum, list_b);
		if (minmax)
			ft_do_rr(&list_a, &list_b, minmax, bestnum, size_a);
		else
			list_b = sort_list_b(list_b, ft_lstsize(list_b));
		ft_do_r(&list_a, &list_b, minmax, bestnum, size_a);
		ft_push(&list_a, &list_b, 'b');
		free (minmax);
	}
	list_a = ft_sort_three(list_a);
	// ft_printf("   LISTA ORDINATA IN B   ");
	// print_list(list_a, list_b);
	list_a = ft_sort_list_back(list_b, list_a);
	return (list_a);
}
