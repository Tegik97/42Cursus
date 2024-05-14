/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:58:50 by mchiaram          #+#    #+#             */
/*   Updated: 2024/04/24 18:23:33 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(&lst->content);
		lst = lst->next;
	}
}

/*				---MAN DESCRIPTION---

	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node.

	---RETURN VALUE---
	None
*/