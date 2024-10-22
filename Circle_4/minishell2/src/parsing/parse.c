/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:00:12 by mchiaram          #+#    #+#             */
/*   Updated: 2024/10/22 12:26:32 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	input_parse(char *input)
{
	t_parse	*data;

	data = malloc(sizeof(t_parse));
	fill_values(input, data);
	while (data)
	{
		printf("data->value: %s\n", data->value);
		data = data->next;
	}
	printf("input: %s\n", input);
	return (0);
}