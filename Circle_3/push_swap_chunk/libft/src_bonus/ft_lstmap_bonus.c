/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:19 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/03 13:22:17 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int *))
{
	t_list	*new_list;
	t_list	*content;
	int		temp;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		temp = f(&lst->content);
		content = ft_lstnew(temp);
		if (!content)
		{
			ft_lstclear(&new_list);
			return (NULL);
		}
		ft_lstadd_back(&new_list, content);
		lst = lst->next;
	}
	return (new_list);
}

/*				---MAN DESCRIPTION---

	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node. Creates a new
	list resulting of the successive applications of
	the function ’f’. The ’del’ function is used to
	delete the content of a node if needed.

	---RETURN VALUE---
	The new list.
	NULL if the allocation fails.
*/