/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:13:32 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/11 16:06:44 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_swap(t_list *list, char c)
{
	t_list	*current;
	int		temp_element;

	if (!list || !list->next)
		return (list);
	current = list;
	temp_element = list->content;
	current = current->next;
	list->content = current->content;
	current->content = temp_element;
	if (c != '0')
		ft_printf("s%c\n", c);
	return (list);
}

void	ft_push(t_list **list_src, t_list **list_dest, char c)
{
	t_list	*new_element;
	t_list	*current;

	if (!(*list_src))
		return ;
	new_element = ft_lstnew((*list_src)->content);
	if (!new_element)
		return ;
	ft_lstadd_front(list_dest, new_element);
	current = (*list_src);
	(*list_src) = (*list_src)->next;
	free (current);
	current = NULL;
	if (c != '0')
		ft_printf("p%c\n", c);
}

// t_list	*ft_rotate(t_list *list, char c) {
//     if (!list || !list->next)
//         return list; // Nessuna rotazione necessaria se la lista è vuota o ha un solo elemento

//     t_list *first = list;
//     t_list *current = list;

//     // Trova l'ultimo nodo
//     while (current->next)
//         current = current->next;

//     // Collega l'ultimo nodo al primo
//     current->next = first;
//     list = first->next; // Nuova testa
//     first->next = NULL; // L'ex primo nodo ora è l'ultimo

//     if (c != '0')
//         ft_printf("r%c\n", c);

//     return list;
// }


t_list	*ft_rotate(t_list *list, char c)
{
	t_list	*current;
	t_list	*list_copy;
	t_list	*new_element;

	if (!list)
		return (list);
	current = list;
	list_copy = list;
	new_element = ft_lstnew(list_copy->content);
	if (!new_element)
		return (list_copy);
	ft_lstadd_back(&list_copy, new_element);
	list_copy = list_copy->next;
	free(current);
	if (c != '0')
		ft_printf("r%c\n", c);
	return (list_copy);
}

t_list	*ft_reverse_rotate(t_list *list, char c)
{
	t_list	*current;
	t_list	*new_element;
	t_list	*list_copy;

	if (!list)
		return (list);
	current = ft_lstlast(list);
	list_copy = list;
	new_element = ft_lstnew(current->content);
	if (!new_element)
		return (list_copy);
	ft_lstadd_front(&list_copy, new_element);
	current = list_copy;
	while (current->next->next)
		current = current->next;
	free(current->next);
	current->next = NULL;
	if (c != '0')
		ft_printf("rr%c\n", c);
	return (list_copy);
}
