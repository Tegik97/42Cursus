/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:14:14 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/08 19:14:19 by mchiaram         ###   ########.fr       */
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

// static int	*ft_fill_array(int *arr, size_t i, t_list *list, size_t size)
// {
// 	size_t	j;

// 	if ((arr[i] == 0 && arr[i + 1] == 0 && arr[size + 1] == 0)
// 		|| (i != 0 && arr[i] == 0 && arr[i + 1] == 0))
// 	{
// 		arr[i] = list->content;
// 		arr[size + 1] = 1;
// 	}
// 	else if (arr[i] >= list->content)
// 	{
// 		j = 0;
// 		while ((size - j) > i)
// 		{
// 			arr[size - j] = arr[(size - 1) - j];
// 			j++;
// 		}
// 		arr[i] = list->content;
// 	}
// 	return (arr);
// }

// static int	*ft_get_index(t_list *list, size_t size)
// {
// 	int		*arr;
// 	size_t	i;

// 	arr = ft_calloc((size + 2), sizeof(list->content));
// 	if (!arr)
// 		return (NULL);
// 	while (list)
// 	{
// 		i = 0;
// 		while (i < size)
// 		{
// 			arr = ft_fill_array(arr, i, list, size);
// 			if (arr[i] == list->content)
// 				break ;
// 			i++;
// 		}
// 		list = list->next;
// 	}
// 	return (arr);
// }

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

t_list	*push_swap(t_list *list)
{
	int		*arr;
	size_t	size;

	size = ft_lstsize(list);
	arr = ft_get_index(list, size);
	list = ft_content_swap(list, arr, size);
	list = ft_check_list(list);
	free (arr);
	return (list);
}
