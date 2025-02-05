#include "minishell.h"

void	free_parse(t_parse *data)
{
	t_parse	*current;

	if (data)
	{
		current = data;
		while (current)
		{
			if (current->value)
			{
				free (current->value);
				current->value = NULL;
			}
			data = data->next;
			free (current);
			current = NULL;
			current = data;
		}
	}
}