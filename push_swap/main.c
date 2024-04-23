/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:51:18 by mchiaram          #+#    #+#             */
/*   Updated: 2024/04/23 20:26:03 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*list_a;
	t_list	*list_b;

	if (argc < 2)
		return (0);
	list_a = NULL;
	list_b = NULL;
	list_a = fill_list(list_a, argv);
	print_list(list_a, list_b);
	ft_printf("\n  SWAP A\n");
	list_a = ft_swap(list_a);
	print_list(list_a, list_b);
	ft_printf("\n  PUSH B\n");
	ft_push(&list_a, &list_b);
	ft_push(&list_a, &list_b);
	print_list(list_a, list_b);
	ft_printf("\n  SWAP B\n");
	list_b = ft_swap(list_b);
	print_list(list_a, list_b);
	ft_printf("\n  PUSH A\n");
	ft_push(&list_b, &list_a);
	ft_push(&list_b, &list_a);
	print_list(list_a, list_b);
	return (0);
}
