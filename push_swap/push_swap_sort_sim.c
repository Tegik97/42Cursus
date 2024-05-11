/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_sim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:02:04 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/11 18:52:01 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_find_index(t_list *list, int target)
{
	size_t	index;
	
	index = 0;
	while (list->content != target)
	{
		list = list->next;
		index++;
	}
	return (index);
}

static size_t	ft_num_moves_r(size_t index_a, size_t index_b, size_t size_a, size_t size_b)
{
	size_t	nmoves;

	nmoves = 0;
	
	while ((index_a > 0 && index_a != size_a) || (index_b > 0 && index_b != size_b))
	{
		if (index_a <= (size_a/2) && index_a != 0)
			index_a--;
		else if (index_a > (size_a/2) && index_a != 0)
			index_a++;
		else if (index_b <= (size_b/2))
			index_b--;
		else if (index_b > (size_b/2))
			index_b++;
		nmoves++;
	}
	return (nmoves);
}

static size_t	ft_num_moves_rr(size_t *index_a, size_t *index_b, size_t size_a, size_t size_b)
{
	size_t	nmoves;
	
	nmoves = 0;
	while ((*index_a > 0 && *index_b > 0) && (*index_a != size_a && *index_b != size_b))
	{
		if ((*index_a > (size_a/2) && *index_b > (size_b/2))
			|| ((*index_a > (size_a/2) && (*index_b + 1) == size_b)))
		{
			(*index_a)++;
			(*index_b)++;
		}
		else if (*index_a <= (size_a/2) && *index_b <= (size_b/2))
		{
			(*index_a)--;
			(*index_b)--;
		}
		nmoves++;
	}
	return (nmoves);
}

static size_t	ft_num_moves(t_list *list_a, t_list *list_b, char *minmax, int target)
{
	size_t	nmoves;
	size_t	size_a;
	size_t	size_b;
	size_t	index_a;
	size_t	index_b;
	
	nmoves = 0;
	size_a = ft_lstsize(list_a);
	size_b = ft_lstsize(list_b);
	index_a = ft_find_index(list_a, target);
	index_b = 0;
	if (minmax)
	{
		index_b = ft_find_index(list_b, ft_atoi(minmax));
		nmoves = ft_num_moves_rr(&index_a, &index_b, size_a, size_b);
	}
	nmoves += ft_num_moves_r(index_a, index_b, size_a, size_b);
	return (nmoves);
}

int	ft_sort_sim(t_list *list_a, t_list *list_b)
{
	size_t	lessmoves;
	size_t	nmoves;
	t_list	*head;
	char	*minmax;
	int		bestnum;
	
	lessmoves = 0;
	bestnum = 0;
	head = list_a;
	while (list_a)
	{
		nmoves = 1;
		minmax = ft_search_min_max(list_a->content, list_b);
		nmoves += ft_num_moves(head, list_b, minmax, list_a->content);
		ft_printf("\nnum: %d -> moves: %d\n", list_a->content, nmoves);
		if (lessmoves > nmoves || lessmoves == 0)
		{
			lessmoves = nmoves;
			bestnum = list_a->content;
		}
		list_a = list_a->next;
	}
	ft_printf("bestnum: %d\n", bestnum);
	return (bestnum);
}

// static size_t	ft_num_moves_r(t_list *list_a, t_list *list_b, char *minmax, int target, size_t size)
// {
// 	size_t	nmoves;
// 	size_t	index_a;
// 	size_t	index_b;

// 	nmoves = 0;
// 	index_a = ft_find_index(list_a, target);
// 	if (minmax)
// 		index_b = ft_find_index(list_b, ft_atoi(minmax));
// 	while (list_a->content != target || list_b->content != ft_atoi(minmax))
// 	{
// 		if (list_a->content != target && index_a <= (size/2))
// 			list_a = ft_rotate(list_a, '0');
// 		else if (list_a->content != target && index_a > (size/2))
// 			list_a = ft_reverse_rotate(list_a, '0');
// 		if (minmax && (list_b->content != ft_atoi(minmax) && index_b <= (size/2)))
// 			list_b = ft_rotate(list_b, '0');
// 		else if (minmax && (list_b->content != ft_atoi(minmax) && index_b > (size/2)))
// 			list_b = ft_reverse_rotate(list_b, '0');
// 		nmoves++;
// 	}
// 	return (nmoves);
// }

// static size_t	ft_num_moves_rr(t_list **list_a, t_list **list_b, char *minmax, int target, size_t size)
// {
// 	size_t	nmoves;
// 	size_t	index_a;
// 	size_t	index_b;
	
// 	nmoves = 0;
// 	index_a = ft_find_index((*list_a), target);
// 	index_b = ft_find_index((*list_b), ft_atoi(minmax));
// 	while ((*list_a)->content != target && (*list_b)->content != ft_atoi(minmax))
// 	{
// 		if (index_a <= (size/2) && index_b <= (size/2))
// 		{
// 			(*list_a) = ft_rotate((*list_a), '0');
// 			(*list_b) = ft_rotate((*list_b), '0');
// 			nmoves++;
// 		}
// 		else if (index_a > (size/2) && index_b > (size/2))
// 		{
// 			(*list_a) = ft_reverse_rotate((*list_a), '0');
// 			(*list_b) = ft_reverse_rotate((*list_b), '0');
// 			nmoves++;
// 		}
// 	}
// 	return (nmoves);
// }