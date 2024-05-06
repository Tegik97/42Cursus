/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:51:18 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/06 22:06:23 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*list_a;
	t_list	*list_b;
	char	**str;

	str = NULL;
	if (argc < 2)
		return (0);
	str = ft_check_params(argc, argv);
	if (!str)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	list_a = NULL;
	list_b = NULL;
	list_a = fill_list(list_a, str);
	if (ft_lstsize(list_a) < 2)
	{
		ft_free_all(&list_a, &list_b, &str);
		return (0);
	}
	list_a = push_swap(list_a);
	print_list(list_a, list_b);
	ft_free_all(&list_a, &list_b, &str);
	return (0);
}
