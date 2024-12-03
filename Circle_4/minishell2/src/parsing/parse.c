/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:00:12 by mchiaram          #+#    #+#             */
/*   Updated: 2024/12/03 15:16:35 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	input_parse(char *input, t_parse *data, t_token *tok)
{
	fill_t_parse_values(input, data);
	fill_t_parse_types(data);
	fill_t_token(data, tok);
	printf("\n");
	while (data)
	{
		printf("data->value: %s\n", data->value);
		printf("data->type: %d\n", data->type);
		printf("\n");
		data = data->next;
	}
	free_all(data);
	return (0);
}
