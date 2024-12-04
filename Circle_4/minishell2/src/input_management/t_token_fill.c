#include "minishell.h"

static void	fill_struct(t_parse *data, t_token *tok, size_t ntok)
{
	t_token	*new_tok;
	t_redir	*new_rd;
	size_t	i;

	new_tok = malloc(sizeof(t_token));
	new_tok->value = malloc(sizeof(char *) * (ntok + 1));
	new_rd = NULL;
	i = 0;
	while (data && data->type != T_PIPE && ntok > 0)
	{
		if (data && (data->type == T_GENERAL || data->type == T_COMMAND
				|| data->type == T_QUOTE || data->type == T_DQUOTE))
			new_tok->value[i++] = data->value;
		else if (data && (data->type == T_RED_IN || data->type == T_RED_OUT
				|| data->type == T_RED_APPEN || data->type == T_RED_APPEN))
		{
			new_rd = malloc(sizeof(t_redir));
			new_rd->type = data->type;
			new_rd->name = data->next->value;
		}
		data = data->next;
	}
	new_tok->value[i] = NULL;
	new_tok->rd = new_rd;
	tok->next = new_tok;
}

static void	first_element(t_parse *data, t_token *tok, size_t ntok)
{
	t_redir	*rd;
	size_t	i;

	tok->value = malloc(sizeof(char *) * (ntok + 1));
	rd = NULL;
	i = 0;
	while (data && data->type != T_PIPE && ntok > 0)
	{
		if (data && (data->type == T_GENERAL || data->type == T_COMMAND
				|| data->type == T_QUOTE || data->type == T_DQUOTE))
			tok->value[i++] = data->value;
		else if (data && (data->type == T_RED_IN || data->type == T_RED_OUT
				|| data->type == T_RED_APPEN || data->type == T_DELIM))
		{
			rd = malloc(sizeof(t_redir));
			rd->type = data->type;
			rd->name = data->next->value;
		}
		data = data->next;
	}
	tok->rd = rd;
	tok->value[i] = NULL;
	tok->next = NULL;
}

static int	n_tokens(t_parse *data)
{
	size_t	ntok;

	ntok = 0;
	while (data && data->type != T_PIPE)
	{
		if (data->type == T_GENERAL || data->type == T_COMMAND
			|| data->type == T_QUOTE || data->type == T_DQUOTE)
			ntok++;
		data = data->next;
	}
	return (ntok);
}

void	fill_t_token(t_parse *data, t_token *tok)
{
	size_t	ntok;

	ntok = n_tokens(data);
	first_element(data, tok, ntok);
	while (ntok-- > 0)
		data = data->next;
	while (data && (data->type != T_GENERAL && data->type != T_COMMAND
			&& data->type != T_QUOTE && data->type != T_DQUOTE))
		data = data->next;
	while (data)
	{
		ntok = n_tokens(data);
		fill_struct(data, tok, ntok);
		while (ntok-- > 0)
			data = data->next;
		while (data && (data->type != T_GENERAL && data->type != T_COMMAND
				&& data->type != T_QUOTE && data->type != T_DQUOTE))
			data = data->next;
		tok = tok->next;
		tok->next = NULL;
	}
}
