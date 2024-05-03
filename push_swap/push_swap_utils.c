/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:13:40 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/03 18:42:36 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_all(t_list **list_a, t_list **list_b, char ***str)
{
	size_t	i;

	i = 0;
	if (list_a)
		ft_lstclear(list_a);
	if (list_b)
		ft_lstclear(list_b);
	i = 0;
	while ((*str)[i])
		free((*str)[i++]);
	free((*str));
}

void	print_list(t_list *list_a, t_list *list_b)
{
	ft_printf("a)\tb)\n");
	while (list_a || list_b)
	{
		if (list_a)
		{
			ft_printf("%d\t", list_a->content);
			list_a = list_a->next;
		}
		else
			ft_printf("\t");
		if (list_b)
		{
			ft_printf("%d\n", list_b->content);
			list_b = list_b->next;
		}
		else
			ft_printf("\n");
	}
}

t_list	*fill_list(t_list *list, char **elements)
{
	t_list	*new_element;
	size_t	i;

	i = 0;
	while (elements[i])
	{
		new_element = ft_lstnew(ft_atoi(elements[i++]));
		ft_lstadd_back(&list, new_element);
	}
	return (list);
}
