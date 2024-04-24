#include "push_swap.h"

void	print_list(t_list *list_a, t_list *list_b)
{
	ft_printf("a)\tb)\n");
	while (list_a || list_b)
	{
		if (list_a)
		{
			ft_printf("%d\t", list_a->content);
			list_a = list_a->next;
		}
		else
			ft_printf("\t");
		if (list_b)
		{
			ft_printf("%d\n", list_b->content);
			list_b = list_b->next;
		}
		else
			ft_printf("\n");
	}
}
t_list	*fill_list(t_list *list, char **elements)
{
	t_list	*new_element;
	size_t	i;

	i = 1;
	while (elements[i])
	{
		new_element = ft_lstnew(ft_atoi(elements[i++]));
		ft_lstadd_back(&list, new_element);
	}
	return (list);
}
