/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:43:03 by mchiaram          #+#    #+#             */
/*   Updated: 2025/01/23 14:39:44 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "struct.h"
# include "parse_utils.h"
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

int		init(t_parse *data, t_token *tok);
void	fill_t_token(t_parse *data, t_token *tok);

#endif