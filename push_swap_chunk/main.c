/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:51:18 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/12 20:42:52 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

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
	list_a = push_swap(list_a, list_b);
	// ft_printf("\n LISTA FINALE  ");
	// print_list(list_a, list_b);
	ft_free_all(&list_a, &list_b, &str);
	return (0);
}


// int	main(void)
// {
// 	t_list	*list_a;
// 	t_list	*list_b;
// 	char	**str;
// 	int		size;
// 	char	**str2;

// 	int int_min, int_max;
// 	size = 501;
// 	str2 = ft_calloc((size + 1), sizeof(char *));
// 	int_min = -1000000;
// 	int_max = 1000000;
//     srand(time(NULL));

//     for (int i = 0; i < size; i++) {
//         int num = int_min + rand() % (int_max - int_min + 1);
// 		str2[i] = ft_itoa(num);
// 		ft_printf("%s ", str2[i]);
//     }
// 	str = ft_check_params(size, str2);
// 	if (!str)
// 	{
// 		ft_putendl_fd("Error", 2);
// 		return (0);
// 	}
// 	list_a = NULL;
// 	list_b = NULL;
// 	list_a = fill_list(list_a, str);
// 	if (ft_lstsize(list_a) < 2)
// 	{
// 		ft_free_all(&list_a, &list_b, &str);
// 		return (0);
// 	}
// 	list_a = push_swap(list_a, list_b);
// 	if (!ft_check_list_sorted(list_a))
// 		ft_putendl_fd("Error!", 2);
// 	ft_free_all(&list_a, &list_b, &str);
// 	return (0);
// }