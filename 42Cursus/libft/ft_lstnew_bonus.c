/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:19:01 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/31 18:24:45 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *) malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%d\n", *(int *)(head->content));
		head = head->next;
	}
}

int	main(void)
{
	t_list	*head = NULL;
	int		i;
	int 	*value;
	
	i = 0;
	while (i < 5)
	{
		value = malloc(sizeof(int) * 1);
		*value = i;

		ft_lstadd_back(&head, ft_lstnew(value));
		i++;
	}
	printf("old list:\n");
	print_list(head);
	*value = 42;
	ft_lstadd_front(&head, ft_lstnew(value));
	printf("\nnew list:\n");
	print_list(head);
	return (0);
}
/*				---MAN DESCRIPTION---

	Allocates (with malloc(3)) and returns a new node.
	The member variable ’content’ is initialized with
	the value of the parameter ’content’. The variable
	’next’ is initialized to NULL.

	---RETURN VALUE---
	The new node
*/