/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:43:01 by mchiaram          #+#    #+#             */
/*   Updated: 2025/01/22 17:25:24 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

enum e_tokenValues
{
	T_GENERAL	= -1,
	T_WHITESPC	= ' ',
	T_TAB		= '\t',
	T_NEWLINE	= '\n',
	T_QUOTE		= '\'',
	T_DQUOTE	= '\"',
	T_RED_IN	= '<',
	T_RED_OUT	= '>',
	T_PIPE		= '|',
	T_VAR		= '$',
	T_EXIT_STAT	= 1024,
	T_DELIM,
	T_RED_APPEN,
	T_COMMAND,
	T_FLAG,
	T_FILE,
	T_BUILTIN
};

typedef struct s_redir
{
	int				type;
	char			*name;
	struct s_redir	*next;
}	t_redir;

typedef struct s_token
{
	char			**value;
	t_redir			*rd;
	struct s_token	*next;
}	t_token;

typedef struct s_parse
{
	char			*value;
	int				type;
	struct s_parse	*next;
}	t_parse;

#endif