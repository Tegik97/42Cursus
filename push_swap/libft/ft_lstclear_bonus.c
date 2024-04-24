/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:35:26 by mchiaram          #+#    #+#             */
/*   Updated: 2024/04/24 18:38:50 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*next;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}

/*				---MAN DESCRIPTION---

	Deletes and frees the given node and every
	successor of that node, using the function ’del’
	and free(3).
	Finally, the pointer to the list must be set to
	NULL.

	---RETURN VALUE---
	None
*/