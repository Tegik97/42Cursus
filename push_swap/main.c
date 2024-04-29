/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:51:18 by mchiaram          #+#    #+#             */
/*   Updated: 2024/04/29 19:12:38 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	CONTROLLARE FT_CHECK_PARAMS  */
int	main(int argc, char *argv[])
{
	t_list	*list_a;
	t_list	*list_b;
	size_t	i;
	char	**str;
	
	str = NULL;
	if (argc >= 2)
		str = ft_check_params(argc, argv);
	if (!str)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	// srand(time(NULL));
	// str = NULL;
	// str = ft_calloc(SIZE, sizeof(char *));
	// i = 0;
	// while (i < SIZE)
	// 	str[i++] = ft_itoa(rand() % 100 + 1);
	list_a = NULL;
	list_b = NULL;
	list_a = fill_list(list_a, str);
	print_list(list_a, list_b);
	ft_lstclear(&list_a);
	ft_lstclear(&list_b);
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}
