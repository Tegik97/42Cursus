#include "minishell.h"

void	threerowstoolong(t_parse *data, char **v, char **v_val, char *str)
{
	free (*(v));
	free(*(v_val));
	free (data->value);
	data->value = ft_strdup(str);
}