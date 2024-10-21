/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:17:58 by mchiaram          #+#    #+#             */
/*   Updated: 2024/10/21 16:51:43 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTILS_H
# define PARSE_UTILS_H

#include "struct.h"

void	free_all(char *input, char *str, t_parse *data);
int		input_parse(char *input);
void	fill_values(char *input, t_parse *data);
int		count_words(char *input);

#endif