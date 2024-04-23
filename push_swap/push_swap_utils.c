#include "push_swap.h"

void	print_list(t_list *list_a, t_list *list_b)
{
	t_list	*current_a;
	t_list	*current_b;

	ft_printf("a)\tb)\n");
	current_a = list_a;
	current_b = list_b;
	while (current_a || current_b)
	{
		if (current_a)
		{
			ft_printf("%d\t", current_a->content);
			current_a = current_a->next;
		}
		else
			ft_printf("\t");
		if (current_b)
		{
			ft_printf("%d\n", current_b->content);
			current_b = current_b->next;
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
