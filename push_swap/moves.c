#include "push_swap.h"

t_list	*ft_swap(t_list *list)
{
	t_list	*current;
	int		temp_element;

	if(!list || !list->next)
		return (list);
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

	if (!(*list_src))
		return ;
	new_element = ft_lstnew((*list_src)->content);
	if (!new_element)
		return ;
	ft_lstadd_front(list_dest, new_element);
	current = (*list_src)->next;
	free(*list_src);
	(*list_src) = current;
}

t_list	*ft_rotate(t_list *list)
{
	t_list	*current;
	t_list	*new_element;

	if (!list)
		return (list);
	current = list;
	new_element = ft_lstnew(list->content);
	if (!new_element)
		return (list);
	ft_lstadd_back(&list, new_element);
	list = list->next;
	free(current);
	return (list);
}

t_list	*ft_reverse_rotate(t_list *list)
{
	t_list	*current;
	t_list	*new_element;

	if (!list)
		return (list);
	current = ft_lstlast(list);
	new_element = ft_lstnew(current->content);
	if (!new_element)
		return (list);
	ft_lstadd_front(&list, new_element);
	current = list;
	while (current->next->next)
		current = current->next;
	free(current->next);
	current->next = NULL;
	return (list);
}