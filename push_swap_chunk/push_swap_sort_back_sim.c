/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_back_sim.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:01:30 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/13 18:05:18 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_num_moves_r(size_t i_a, size_t i_b, size_t s_a, size_t s_b)
{
	size_t	nmoves;

	nmoves = 0;
	while ((i_a > 0 && i_a != s_a) || (i_b > 0 && i_b != s_b))
	{
		if (i_a <= (s_a / 2) && i_a != 0)
			i_a--;
		else if (i_a > (s_a / 2) && i_a != s_a)
			i_a++;
		else if (i_b <= (s_b / 2))
			i_b--;
		else if (i_b > (s_b / 2))
			i_b++;
		nmoves++;
	}
	return (nmoves);
}

static size_t	ft_n_moves_rr(size_t *i_a, size_t *i_b, size_t s_a, size_t s_b)
{
	size_t	nmoves;

	nmoves = 0;
	while ((*i_a > 0 && *i_b > 0) && (*i_a != s_a && *i_b != s_b))
	{
		if ((*i_a > (s_a / 2) && *i_b > (s_b / 2))
			|| (*i_a >= (s_a / 2) && (*i_b + 1) == s_b))
		{
			(*i_a)++;
			(*i_b)++;
		}
		else if (*i_a <= (s_a / 2) && *i_b <= (s_b / 2))
		{
			(*i_a)--;
			(*i_b)--;
		}
		else
			break ;
		nmoves++;
	}
	return (nmoves);
}

static size_t	sort_a_sim(t_list *list_a, size_t size)
{
	t_list	*current;
	int		min;
	size_t	index;
	size_t	nmoves;

	min = INT_MAX;
	current = list_a;
	nmoves = 0;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	index = ft_find_index(list_a, min);
	while (index > 0 && index != size)
	{
		if (index > (size / 2) || index == (size - 1))
			index++;
		else
			index--;
		nmoves++;
	}
	return (nmoves);
}

static size_t	ft_num_moves(t_list *l_b, t_list *l_a, char *maxmin, int target)
{
	size_t	nmoves;
	size_t	size_a;
	size_t	size_b;
	size_t	index_a;
	size_t	index_b;

	nmoves = 0;
	size_a = ft_lstsize(l_a);
	size_b = ft_lstsize(l_b);
	index_b = ft_find_index(l_b, target);
	index_a = 0;
	if (maxmin)
	{
		index_a = ft_find_index(l_a, ft_atoi(maxmin));
		nmoves = ft_n_moves_rr(&index_a, &index_b, size_a, size_b);
	}
	else
		nmoves += sort_a_sim(l_a, ft_lstsize(l_a));
	nmoves += ft_num_moves_r(index_a, index_b, size_a, size_b);
	return (nmoves);
}

int	ft_sort_back_sim(t_list *list_b, t_list *list_a)
{
	size_t	lessmoves;
	size_t	nmoves;
	t_list	*head;
	char	*maxmin;
	int		bestnum;

	lessmoves = 0;
	bestnum = 0;
	head = list_b;
	while (list_b)
	{
		nmoves = 1;
		maxmin = ft_search_max_min(list_b->content, list_a);
		nmoves += ft_num_moves(head, list_a, maxmin, list_b->content);
		free (maxmin);
		if (lessmoves > nmoves || lessmoves == 0)
		{
			lessmoves = nmoves;
			bestnum = list_b->content;
			if (lessmoves == 1)
				break ;
		}
		list_b = list_b->next;
	}
	return (bestnum);
}
