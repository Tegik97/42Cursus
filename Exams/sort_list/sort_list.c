t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		temp;
	t_list	*head;

	head = lst;
	while (lst->next)
	{
		if (!cmp(lst->data, lst->next->data))
		{
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = head;
		}
		else
			lst = lst->next;
	}
	return (head);
}