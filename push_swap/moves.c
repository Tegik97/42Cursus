#include "push_swap.h"

t_list	*ft_swap(t_list *list)
{
	t_list	*current;
	int		temp_element;

	current = list;
	temp_element = list->content;
	current = current->next;
	list->content = current->content;
	current->content = temp_element;
	return (list);
}

void	ft_push(t_list **list_src, t_list **list_dest)
{
	t_list	*new_element;
	t_list	*current;
	int		element;
	
	element = (*list_src)->content;
	new_element = ft_lstnew(element);
	ft_lstadd_front(list_dest, new_element);
	current = (*list_src);
	(*list_src) = (*list_src)->next;
	free(current);
}
