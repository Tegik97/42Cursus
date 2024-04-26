/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:51:18 by mchiaram          #+#    #+#             */
/*   Updated: 2024/04/26 16:42:20 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#ifndef SIZE
# define SIZE 100
#endif

int	main(int argc, char *argv[])
{
	t_list	*list_a;
	t_list	*list_b;
	size_t	i;
	char	**str;
	
	if (argc < 1 || argv[0][0] == 'c')
		return (0);
	srand(time(NULL));
	str = NULL;
	i = 0;
	str = ft_calloc(SIZE, sizeof(char *));
	while (i < SIZE)
		str[i++] = ft_itoa(rand() % 100 + 1);
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
