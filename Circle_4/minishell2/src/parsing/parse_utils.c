/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:23:52 by mchiaram          #+#    #+#             */
/*   Updated: 2024/10/22 12:25:07 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cmd_len(char *input)
{
	size_t	len;

	len = 0;
	while (*input && (*input != ' ' &&
			*input != '\n' && *input != '\t'))
	{
		len++;
		input++;
	}
	return (len);
}

void	fill_values(char *input, t_parse *data)
{
	size_t	size;
	t_parse	*new_element;

	input = ft_strtrim(input, " \t\n");
	size = cmd_len(input);
	data->value = ft_stringlcopy(data->value, input, size);
	input += size;
	data->next = NULL;
	while (*input)
	{
		new_element = malloc(sizeof(t_parse));
		input = ft_strtrim(input, " \t\n");
		size = cmd_len(input);
		new_element->value = ft_stringlcopy(data->value, input, size);
		input += size;
		data->next = new_element;
		data = data->next;
	}
	data->next = NULL;
}
