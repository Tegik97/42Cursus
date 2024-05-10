/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:04:44 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/10 12:13:36 by menny            ###   ########.fr       */
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

static t_list	*ft_sort_alg(t_list *list_a, t_list *list_b)
{
	if (ft_lstsize(list_a) == 4)
		ft_push(&list_a, &list_b, 'b');
	else
	{
		ft_push(&list_a, &list_b, 'b');
		ft_push(&list_a, &list_b, 'b');
	}
	while (ft_lstsize(list_a) > 3)
		ft_printf("");
	list_a = ft_sort_three(list_a);
	print_list(list_a, list_b);
	return (list_a);
}
t_list	*ft_sort(t_list *list_a, t_list *list_b)
{
	if (ft_lstsize(list_a) < 4)
		list_a = ft_sort_three(list_a);
	else
		list_a = ft_sort_alg(list_a, list_b);
	return (list_a);
}
int	ft_check_list_sorted(t_list *list)
{
	while (list->next)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}