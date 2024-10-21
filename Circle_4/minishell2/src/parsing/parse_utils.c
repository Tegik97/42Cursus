/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:23:52 by mchiaram          #+#    #+#             */
/*   Updated: 2024/10/21 16:55:05 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cmd_len(char *input)
{
	size_t	len;

	len = 0;
	while (*input && (*input == ' ' ||
			*input == "\n" || *input == "\t"))
		input++;
	while (*input && (*input != ' ' ||
			*input != "\n" || *input != "\t"))
	{
		len++;
		input++;
	}
	return (len);
}

//controllare newelement e allocazione memoria
void	fill_values(char *input, t_parse *data)
{
	size_t	i;
	t_parse	*new_element;

	while (*input)
	{
		i = 0;
		data->value = ft_calloc(cmd_len(input), sizeof(char));
		while (*input && (*input == ' ' ||
			*input == "\n" || *input == "\t"))
		input++;
		while (*input && (*input != ' ' ||
				*input != "\n" || *input != "\t"))
			data->value[i++] = input++;
		data = data->next;
	}
}
