#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
			ft_lstclear(&new_list, del);
		new_list = new_node;
		new_node = new_node->next;
		lst = lst->next;
	}
	return (new_list);
}
