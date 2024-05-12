/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_sim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:02:04 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/12 14:52:11 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_num_moves_r(size_t index_a, size_t index_b, size_t size_a, size_t size_b)
{
	size_t	nmoves;

	nmoves = 0;
	
	while ((index_a > 0 && index_a != size_a) || (index_b > 0 && index_b != size_b))
	{
		if (index_a <= (size_a/2) && index_a != 0)
			index_a--;
		else if (index_a > (size_a/2) && index_a != size_a)
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
			|| ((*index_a >= (size_a/2) && (*index_b + 1) == size_b)))
		{
			(*index_a)++;
			(*index_b)++;
		}
		else if (*index_a <= (size_a/2) && *index_b <= (size_b/2))
		{
			(*index_a)--;
			(*index_b)--;
		}
		else
			break ;
		nmoves++;
	}
	return (nmoves);
}

static size_t	sort_b_sim(t_list *list_b, size_t size)
{
	t_list	*current;
	int		max;
	size_t	index;
	size_t	nmoves;
	
	max = INT_MIN;
	current = list_b;
	nmoves = 0;
	while (current)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	index = ft_find_index(list_b, max);
	while (index > 0 && index != size)
	{
		if (index > (size/2) || index == (size - 1))
			index++;
		else
			index--;
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
	else
		nmoves += sort_b_sim(list_b, ft_lstsize(list_b));
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
		free (minmax);
		if (lessmoves > nmoves || lessmoves == 0)
		{
			lessmoves = nmoves;
			bestnum = list_a->content;
			if (lessmoves == 1)
				break ;
		}
		list_a = list_a->next;
	}
	return (bestnum);
}
