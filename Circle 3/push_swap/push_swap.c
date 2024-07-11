/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:14:14 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/12 19:16:17 by menny            ###   ########.fr       */
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

static void	sort_list_final(t_list *list_a, int *min, size_t *min_index)
{
	t_list	*current;
	size_t	i;
	
	*min = INT_MAX;
	*min_index = 0;
	current = list_a;
	i = 0;
	while (current)
	{
		if (current->content < *min)
		{
			*min = current->content;
			*min_index = i;
		}
		current = current->next;
		i++;
	}
}

t_list	*push_swap(t_list *list_a, t_list *list_b)
{
	int		*arr;
	size_t	size;
	int		min;
	size_t	min_index;

	if (ft_check_list_sorted(list_a))
		return (list_a);
	size = ft_lstsize(list_a);
	arr = ft_get_index(list_a, size);
	list_a = ft_content_swap(list_a, arr, size);
	// ft_printf(" LISTA INDICIZZATA   \n");
	// print_list(list_a, list_b);
	list_a = ft_sort(list_a, list_b, size);
	if (!ft_check_list_sorted(list_a))
	{
		sort_list_final(list_a, &min, &min_index);
		while (list_a->content != min)
		{
		if (min_index > (size/2) || min_index == (size - 1))
			list_a = ft_reverse_rotate(list_a, 'a');
		else
			list_a = ft_rotate(list_a, 'a');
		}
	}
	free (arr);
	return (list_a);
}
