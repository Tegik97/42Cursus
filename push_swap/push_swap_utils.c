#include "push_swap.h"

// void	ft_print_error()
// {
// 	ft_putendl_fd("Error", 2);
// }

char	**ft_check_params(int argc, char **argv)
{
	char	**str;
	int		i;
	int		x;
	size_t	j;

	j = 0;
	i = 1;
	if (argc > 2)
	{
		str = ft_calloc(argc, sizeof(char *));
		while (i < argc)
		{
			x = 0;
			while (argv[i][x])
			{
				/*must free the allocated memory if this check is true*/
				if (!ft_isdigit(argv[i][x++]))
					return (NULL);
			}
			ft_strlcpy(&str[j++], argv[i++]);
		}
	}
	else
		str = ft_split(argv[1], ' ');
	return (str);
}

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

	i = 0;
	while (elements[i])
	{
		new_element = ft_lstnew(ft_atoi(elements[i++]));
		ft_lstadd_back(&list, new_element);
	}
	return (list);
}
