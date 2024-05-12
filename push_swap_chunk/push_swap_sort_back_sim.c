#include "push_swap.h"

static size_t	ft_num_moves_r(size_t index_a, size_t index_b, size_t size_a, size_t size_b)
{
	size_t	nmoves;

	nmoves = 0;
	
	while ((index_a > 0 && index_a != size_a) || (index_b > 0 && index_b != size_b))
	{
		if (index_a <= (size_a/2) && index_a != 0)
			index_a--;
		else if (index_a > (size_a/2) && index_a != size_a)
			index_a++;
		else if (index_b <= (size_b/2))
			index_b--;
		else if (index_b > (size_b/2))
			index_b++;
		nmoves++;
	}
	return (nmoves);
}

static size_t	ft_num_moves_rr(size_t *index_a, size_t *index_b, size_t size_a, size_t size_b)
{
	size_t	nmoves;
	
	nmoves = 0;
	while ((*index_a > 0 && *index_b > 0) && (*index_a != size_a && *index_b != size_b))
	{
		if ((*index_a > (size_a/2) && *index_b > (size_b/2))
			|| ((*index_a >= (size_a/2) && (*index_b + 1) == size_b)))
		{
			(*index_a)++;
			(*index_b)++;
		}
		else if (*index_a <= (size_a/2) && *index_b <= (size_b/2))
		{
			(*index_a)--;
			(*index_b)--;
		}
		else
			break ;
		nmoves++;
	}
	return (nmoves);
}

static size_t	sort_a_sim(t_list *list_a, size_t size)
{
	t_list	*current;
	int		min;
	size_t	index;
	size_t	nmoves;
	
	min = INT_MAX;
	current = list_a;
	nmoves = 0;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	index = ft_find_index(list_a, min);
	while (index > 0 && index != size)
	{
		if (index > (size/2) || index == (size - 1))
			index++;
		else
			index--;
		nmoves++;
	}
	return (nmoves);
}

static size_t	ft_num_moves(t_list *list_b, t_list *list_a, char *maxmin, int target)
{
	size_t	nmoves;
	size_t	size_a;
	size_t	size_b;
	size_t	index_a;
	size_t	index_b;
	
	nmoves = 0;
	size_a = ft_lstsize(list_a);
	size_b = ft_lstsize(list_b);
	index_b = ft_find_index(list_b, target);
	index_a = 0;
	if (maxmin)
	{
		index_a = ft_find_index(list_a, ft_atoi(maxmin));
		nmoves = ft_num_moves_rr(&index_a, &index_b, size_a, size_b);
	}
	else
		nmoves += sort_a_sim(list_a, ft_lstsize(list_a));
	nmoves += ft_num_moves_r(index_a, index_b, size_a, size_b);
	return (nmoves);
}

int	ft_sort_back_sim(t_list *list_b, t_list *list_a)
{
	size_t	lessmoves;
	size_t	nmoves;
	t_list	*head;
	char	*maxmin;
	int		bestnum;
	
	lessmoves = 0;
	bestnum = 0;
	head = list_b;
	while (list_b)
	{
		nmoves = 1;
		maxmin = ft_search_max_min(list_b->content, list_a);
		nmoves += ft_num_moves(head, list_a, maxmin, list_b->content);
		free (maxmin);
		if (lessmoves > nmoves || lessmoves == 0)
		{
			lessmoves = nmoves;
			bestnum = list_b->content;
			if (lessmoves == 1)
				break ;
		}
		list_b = list_b->next;
	}
	return (bestnum);
}
