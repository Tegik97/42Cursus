/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:00:12 by mchiaram          #+#    #+#             */
/*   Updated: 2024/12/04 11:55:53 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	input_parse(char *input, t_parse *data, t_token *tok)
{
	size_t	i;
	size_t	j;

	fill_t_parse_values(input, data);
	fill_t_parse_types(data);
	fill_t_token(data, tok);
	printf("\n");
	j = 0;
	while (tok)
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
	// free_all(data);
	return (0);
}
