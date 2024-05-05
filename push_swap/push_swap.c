/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:14:14 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/05 22:23:00 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list *ft_content_swap(t_list *list, int *arr)
{
	size_t	i;
	t_list	*current;

	current = list;
	while (current)
	{
		i = 0;
		while (arr[i])
		{
			ft_printf("%d\n", current->content);
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

static int	*ft_check_array(int *arr, t_list *list, size_t size)
{
	size_t	i;
	size_t	j;
	i = 0;
	while (i <= size)
	{
		if (arr[i] == '\0')
		{
			arr[i] = list->content;
			break ;
		}
		else if (arr[i] > list->content)
		{
			j = 0;
			while ((size - j) > i)
			{
				arr[size - j] = arr[(size - 1) - j];
				j++;
			}
			arr[i] = list->content;
			break ;
		}
		i++;
	}
	return (arr);
}

static int	*ft_get_index(t_list *list)
{
	int		*arr;
	size_t	size;
	
	size = ft_lstsize(list);
	arr = ft_calloc((size + 1), sizeof(list->content));
	if (!arr)
		return (NULL);
	while (list)
	{
		arr = ft_check_array(arr, list, size);
		list = list->next;
	}
	return (arr);
}

t_list	*push_swap(t_list *list)
{
	int		*arr;

	arr = ft_get_index(list);
	list = ft_content_swap(list, arr);
	free (arr);
	return (list);
}