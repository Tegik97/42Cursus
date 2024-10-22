/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_values_fill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:43:43 by mchiaram          #+#    #+#             */
/*   Updated: 2024/10/22 15:58:17 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	token_len(char *input)
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

static char	*list_element(char *input, t_parse *data)
{
	t_parse	*new_element;
	size_t	size;
	
	while (*input)
	{
		new_element = malloc (sizeof(t_parse));
		while (*input && (*input == ' ' ||
			*input == '\t' || *input == '\n'))
		input++;
		size = token_len(input);
		new_element->value = ft_stringlcopy(new_element->value, input, size);
		data->next = new_element;
		data = data->next;
		input += size;
	}
	data->next = NULL;
	return (input);
}

static char	*first_element(char *input, t_parse *data)
{
	size_t	size;

	while (*input && (*input == ' ' ||
		*input == '\t' || *input == '\n'))
	input++;
	size = token_len(input);
	data->value = ft_stringlcopy(data->value, input, size);
	input += size;
	return (input);
}

void	fill_values(char *input, t_parse *data)
{
	input = first_element(input, data);
	input = list_element(input, data);
}
