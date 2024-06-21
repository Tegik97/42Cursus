/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:20:26 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/14 23:07:03 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	do_swap_push(t_list **list_a, t_list **list_b, char *move)
{
	if (ft_strncmp(move, "pa\n", ft_strlen(move)) == 0)
		ft_push(list_b, list_a, '0');
	else if (ft_strncmp(move, "pb\n", ft_strlen(move)) == 0)
		ft_push(list_a, list_b, '0');
	else if (ft_strncmp(move, "sa\n", ft_strlen(move)) == 0)
		*list_a = ft_swap((*list_a), '0');
	else if (ft_strncmp(move, "sb\n", ft_strlen(move)) == 0)
		*list_b = ft_swap((*list_b), '0');
	else
		return (0);
	return (1);
}

static int	do_moves(t_list **list_a, t_list **list_b, char *move)
{
	if (do_swap_push(list_a, list_b, move))
		return (1);
	if (ft_strncmp(move, "ra\n", ft_strlen(move)) == 0)
		*list_a = ft_rotate((*list_a), '0');
	else if (ft_strncmp(move, "rb\n", ft_strlen(move)) == 0)
		*list_b = ft_rotate((*list_b), '0');
	else if (ft_strncmp(move, "rr\n", ft_strlen(move)) == 0)
	{
		*list_a = ft_rotate((*list_a), '0');
		*list_b = ft_rotate((*list_b), '0');
	}
	else if (ft_strncmp(move, "rra\n", ft_strlen(move)) == 0)
		*list_a = ft_reverse_rotate((*list_a), '0');
	else if (ft_strncmp(move, "rrb\n", ft_strlen(move)) == 0)
		*list_b = ft_reverse_rotate((*list_b), '0');
	else if (ft_strncmp(move, "rrr\n", ft_strlen(move)) == 0)
	{
		*list_a = ft_reverse_rotate((*list_a), '0');
		*list_b = ft_reverse_rotate((*list_b), '0');
	}
	else
		return (0);
	return (1);
}

static int	ft_check_moves(t_list **list_a, t_list **list_b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (!do_moves(list_a, list_b, move))
		{
			ft_putendl_fd("Error", 2);
			free (move);
			get_next_line(-42);
			return (0);
		}
		free (move);
		move = get_next_line(0);
	}
	if (ft_check_list_sorted(*list_a) && ft_lstsize(*list_b) == 0)
		ft_putendl_fd("OK", 2);
	else
		ft_putendl_fd("KO", 2);
	free (move);
	move = get_next_line(-42);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*list_a;
	t_list	*list_b;
	char	**str;

	str = NULL;
	if (argc < 2)
		return (1);
	str = ft_check_params(argc, argv);
	if (!str)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	list_a = NULL;
	list_b = NULL;
	list_a = fill_list(list_a, str);
	if (ft_lstsize(list_a) < 2)
	{
		ft_free_all(&list_a, &list_b, &str);
		return (1);
	}
	list_a = push_swap(list_a);
	ft_check_moves(&list_a, &list_b);
	ft_free_all(&list_a, &list_b, &str);
	return (0);
}
