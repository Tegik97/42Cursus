#include "minishell.h"

static int	n_tokens(t_parse *data)
{
	size_t	ntok;

	ntok = 0;
	while (data && (data->type == T_GENERAL || data->type == T_COMMAND
			|| data->type == T_QUOTE || data->type == T_DQUOTE))
	{
		ntok++;
		data = data->next;
	}
	return (ntok);
}

void	fill_t_token(t_parse *data, t_token *tok)
{
	size_t	ntok;

	while (data)
	{
		ntok = n_tokens(data);
		while (ntok-- > 0)
			data = data->next;
		while (data && (data->type != T_GENERAL && data->type != T_COMMAND
				&& data->type != T_QUOTE && data->type != T_DQUOTE))
			data = data->next;
	}
	tok = (void *) tok;
}
