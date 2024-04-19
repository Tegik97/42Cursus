/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:51:18 by mchiaram          #+#    #+#             */
/*   Updated: 2024/04/19 21:41:26 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	int	i;
	t_list *pushswap;
	t_list *new;
	t_list *current;
	
	pushswap = NULL;
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i++]));
		ft_lstadd_back(&pushswap, new);
	}
	current = pushswap;
	while (current)
	{
		ft_printf("%d\n", current->content);
		current = current->next;
	}
	return (0);
}