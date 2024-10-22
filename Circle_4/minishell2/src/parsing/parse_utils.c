/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:23:52 by mchiaram          #+#    #+#             */
/*   Updated: 2024/10/22 14:44:21 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	fill_values(char *input, t_parse *data)
// {
// 	size_t	size;
// 	char	*str;
// 	t_parse	*new_element;

// 	str = ft_strtrim(input, " \t\n");
// 	size = cmd_len(str);
// 	data->value = ft_stringlcopy(data->value, str, size);
// 	free (str);
// 	input += size;
// 	data->next = NULL;
// 	while (*input)
// 	{
// 		new_element = malloc(sizeof(t_parse));
// 		input = ft_strtrim(input, " \t\n");
// 		size = cmd_len(input);
// 		new_element->value = ft_stringlcopy(data->value, input, size);
// 		input += size;
// 		data->next = new_element;
// 		data = data->next;
// 	}
// 	data->next = NULL;
// }
