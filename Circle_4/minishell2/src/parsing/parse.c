/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:00:12 by mchiaram          #+#    #+#             */
/*   Updated: 2025/01/24 15:13:43 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	input_parse(char *input, t_parse *data, t_token *tok)
{
	size_t	i;
	size_t	j;

	if (!fill_t_parse_values(input, data) || !fill_t_parse_types(data))
		return (0);
	fill_t_token(data, tok);
	printf("\n");
	j = 0;
	while (tok) //stampa valori
	{
		i = 0;
		while (tok->value[i])
			printf("tok%ld->value: %s\n", j, tok->value[i++]);
		if (tok->rd)
			printf("tok%ld->rd->type: %d\ntok%ld->rd->name: %s\n", j, tok->rd->type, j, tok->rd->name);
		printf("\n");
		tok = tok->next;
		j++;
	}
	// while (data)
	// {
	// 	printf("value: %s, type: %d\n", data->value, data->type);
	// 	data = data->next;
	// }
	return (0);
}
