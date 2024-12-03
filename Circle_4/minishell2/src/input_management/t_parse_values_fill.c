/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parse_values_fill.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:43:43 by mchiaram          #+#    #+#             */
/*   Updated: 2024/12/03 11:46:16 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_quotes(char *input, int type)
{
	size_t	len;

	len = 0;
	input++;
	while (*input && *input != type)
	{
		len++;
		input++;
	}
	len += 2;
	if (!*input)
	{
		printf("ERROR: Quotes must be closed\n");
		len = 0;
	}
	return (len);
}

static int	token_len(char *input)
{
	size_t	len;
	int		type;

	len = 0;
	type = *input;
	if (type == T_DQUOTE || type == T_QUOTE)
		len = check_quotes(input, type);
	else
	{
		while (*input && (*input != ' ' && *input != '\n' && *input != '\t'
				&& *input != '|' && *input != '<' && *input != '>'))
		{
			len++;
			input++;
		}
		if (len == 0 && (*input == '|' || *input == '<' || *input == '>'))
		{
			len = 1;
			if ((*input == '<' && *(input + 1) == '<')
				|| (*input == '>' && *(input + 1) == '>'))
				len = 2;
		}
	}
	return (len);
}

static char	*first_value(t_parse *data, char *input)
{
	size_t	size;

	size = token_len(input);
	data->value = ft_stringlcopy(data->value, input, size);
	data->type = T_GENERAL;
	if (!size)
	{
		data->next = NULL;
		return ("\0");
	}
	return (input + size);
}

void	fill_t_parse_values(char *input, t_parse *data)
{
	t_parse	*new_element;
	size_t	size;

	while (*input && (*input == ' ' || *input == '\t' || *input == '\n'))
		input++;
	if (input)
		input = first_value(data, input);
	while (*input)
	{
		while (*input && (*input == ' ' || *input == '\t' || *input == '\n'))
			input++;
		if (!*input)
			break ;
		new_element = malloc (sizeof(t_parse));
		size = token_len(input);
		new_element->value = ft_stringlcopy(new_element->value, input, size);
		new_element->type = T_GENERAL;
		data->next = new_element;
		data = data->next;
		if (!size)
			break ;
		input += size;
	}
	data->next = NULL;
}
