/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:17:58 by mchiaram          #+#    #+#             */
/*   Updated: 2024/12/03 15:26:50 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTILS_H
# define PARSE_UTILS_H

# include "struct.h"

void	free_all(t_parse *data);
int		input_parse(char *input, t_parse *data, t_token *tok);
void	fill_t_parse_values(char *input, t_parse *data);
void	fill_t_parse_types(t_parse *data);
int		count_words(char *input);

#endif