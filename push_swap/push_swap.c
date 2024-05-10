/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:14:14 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/10 12:02:00 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_content_swap(t_list *list, int *arr, size_t size)
{
	size_t	i;
	t_list	*current;

	current = list;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->content == arr[i])
			{
				current->content = i;
				current = current->next;
				break ;
			}
			i++;
		}
	}
	return (list);
}

static int	*ft_sort_array(int *arr, size_t size)
{
	int		temp;
	size_t	i;

	i = 0;
	while (i < (size - 1))
	{
		i++;
		if (arr[i - 1] > arr[i])
		{
			temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;
			i = 0;
		}
	}
	return (arr);
}

static int	*ft_get_index(t_list *list, size_t size)
{
	int		*arr;
	size_t	i;

	arr = ft_calloc((size + 1), sizeof(list->content));
	if (!arr)
		return (NULL);
	i = 0;
	while (list)
	{
		arr[i] = list->content;
		list = list->next;
		i++;
	}
	arr = ft_sort_array(arr, size);
	return (arr);
}

t_list	*push_swap(t_list *list_a, t_list *list_b)
{
	int		*arr;
	size_t	size;

	if (ft_check_list_sorted(list_a))
		return (list_a);
	size = ft_lstsize(list_a);
	arr = ft_get_index(list_a, size);
	list_a = ft_content_swap(list_a, arr, size);
	list_a = ft_sort(list_a, list_b);
	free (arr);
	return (list_a);
}
