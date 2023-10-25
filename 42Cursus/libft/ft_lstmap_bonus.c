#include "libft.h"
/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = ft_lstnew(f(lst->content));
		if (!content)
		{
			ft_lstclear(&new_list, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&new_list, content);
		lst = lst->next;
	}
	return (new_list);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*content;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		temp = f(lst->content);
		content = ft_lstnew(temp);
		if (!content)
		{
			ft_lstclear(&new_list, del);
			del(temp);
			return (NULL);
		}
		ft_lstadd_back(&new_list, content);
		lst = lst->next;
	}
	return (new_list);
}
