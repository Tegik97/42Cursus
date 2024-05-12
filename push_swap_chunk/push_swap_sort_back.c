#include "push_swap.h"

static void	ft_do_r(t_list **list_b, t_list **list_a, char *minmax, int target, size_t size_b)
{
	size_t	index_a;
	size_t	index_b;
	size_t	size_a;

	size_a = ft_lstsize((*list_a));
	index_b = ft_find_index((*list_b), target);
	index_a = 0;
	if (minmax)
		index_a = ft_find_index((*list_a), ft_atoi(minmax));
	while ((*list_b)->content != target || (minmax && (*list_a)->content != ft_atoi(minmax)))
	{
		if ((*list_b)->content != target && index_b <= (size_b / 2)
			&& index_b != 0)
			(*list_b) = ft_rotate((*list_b), 'b');
		else if ((*list_b)->content != target && index_b > (size_b / 2)
			&& index_b != size_b)
			(*list_b) = ft_reverse_rotate((*list_b), 'b');
		else if (minmax && ((*list_a)->content != ft_atoi(minmax)
			&& index_a <= (size_a / 2)))
			(*list_a) = ft_rotate((*list_a), 'a');
		else if (minmax && ((*list_a)->content != ft_atoi(minmax)
			&& index_a > (size_a / 2)))
			(*list_a) = ft_reverse_rotate((*list_a), 'a');
	}
}

// static void	ft_do_rr(t_list **list_a, t_list **list_b, char *minmax, int target, size_t size)
// {
// 	size_t	index_a;
// 	size_t	index_b;
// 	size_t	size_b;
	
// 	size_b = ft_lstsize((*list_b));
// 	index_a = ft_find_index((*list_a), target);
// 	index_b = ft_find_index((*list_b), ft_atoi(minmax));
// 	while ((*list_a)->content != target && (*list_b)->content != ft_atoi(minmax))
// 	{
// 		if ((index_a > (size/2) && index_b > (size_b/2))
// 		|| ((index_a > (size/2) && (index_b + 1) == size_b)))
// 		{
// 			(*list_a) = ft_reverse_rotate((*list_a), '0');
// 			(*list_b) = ft_reverse_rotate((*list_b), 'r');
// 		} 
// 		else if (index_a <= (size/2) && index_b <= (size_b/2))
// 		{
// 			(*list_a) = ft_rotate((*list_a), '0');
// 			(*list_b) = ft_rotate((*list_b), 'r');
// 		}
// 		else
// 			break ;
// 	}
// }

static void	ft_do_rr(t_list **list_b, t_list **list_a, char *minmax, int target, size_t size_b)
{
	size_t	index_a;
	size_t	index_b;
	size_t	size_a;
	
	size_a = ft_lstsize((*list_a));
	index_b = ft_find_index((*list_b), target);
	index_a = ft_find_index((*list_a), ft_atoi(minmax));
	while ((*list_b)->content != target && (*list_a)->content != ft_atoi(minmax))
	{
		if ((index_b > (size_b / 2) && index_a > (size_a / 2))
		|| (index_b > (size_b / 2) && (index_a + 1) == size_a))
		{
			(*list_a) = ft_reverse_rotate((*list_a), '0');
			(*list_b) = ft_reverse_rotate((*list_b), 'r');
		} 
		else if (index_b <= (size_b / 2) && index_a <= (size_a / 2))
		{
			(*list_a) = ft_rotate((*list_a), '0');
			(*list_b) = ft_rotate((*list_b), 'r');
		}
		else
			break ;
	}
}

char	*ft_search_max_min(int content, t_list *list)
{
	char	*maxmin;
	int		diff;
	
	diff = 0;
	maxmin = NULL;
	while (list)
	{
		if (list->content > content)
		{
			if ((content - list->content) > diff || diff == 0)
			{
				diff = content - list->content;
				free (maxmin);
				maxmin = ft_itoa(list->content);
			}
		}
		list = list->next;
	}
	return (maxmin);
}

static t_list	*sort_list_a(t_list *list_a, size_t size)
{
	t_list	*current;
	int		min;
	size_t	index;
	
	min = INT_MAX;
	current = list_a;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	index = ft_find_index(list_a, min);
	while (list_a->content != min)
	{
		if (index > (size / 2) || index == (size - 1))
			list_a = ft_reverse_rotate(list_a, 'a');
		else
			list_a = ft_rotate(list_a, 'a');
	}
	return (list_a);
}

t_list	*ft_sort_list_back(t_list *list_b, t_list *list_a)
{
	int		bestnum;
	char	*maxmin;
	size_t	size_b;

	maxmin = NULL;
	while (ft_lstsize(list_b) > 0)
	{
		size_b = ft_lstsize(list_b);
		bestnum = ft_sort_back_sim(list_b, list_a);
		maxmin = ft_search_max_min(bestnum, list_a);
		if (maxmin)
			ft_do_rr(&list_b, &list_a, maxmin, bestnum, size_b);
		else
			list_a = sort_list_a(list_a, ft_lstsize(list_a));
		ft_do_r(&list_b, &list_a, maxmin, bestnum, size_b);
		ft_push(&list_b, &list_a, 'a');
		free(maxmin);
	}
	return (list_a);
}
