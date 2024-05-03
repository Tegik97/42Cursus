/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:10:51 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/03 18:44:24 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_search_spaces(char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == ' ')
				return (0);
			j++;
		}
	}
	return (1);
}

static int	ft_check_next_char(char **str)
{
	size_t	i;
	size_t	j;

	if (!str)
		return (0);
	i = 0;
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] == '+' || str[i][j] == '-') && (str[i][j + 1] < '0'
				|| str[i][j + 1] > '9' || str[i][j + 1] == '\0'))
				return (0);
			else if ((str[i][j] >= '0' && str[i][j] <= '9') &&
					(str[i][j + 1] < '0' || str[i][j + 1] > '9') &&
					str[i][j + 1] != ' ' && str[i][j + 1] != '\0')
				return (0);
			j++;
		}
	}
	return (1);
}

static int	ft_check_dups(char	**str)
{
	char	**mat;
	size_t	nmemb;
	size_t	i;

	nmemb = 0;
	while (str[nmemb])
		nmemb++;
	mat = ft_calloc((nmemb + 1), sizeof(char *));
	nmemb = 0;
	while (str[nmemb])
	{
		i = 0;
		while (mat[i])
		{
			if (ft_atoi(str[nmemb]) == ft_atoi(mat[i++]))
			{
				free(mat);
				return (0);
			}
		}
		mat[i] = str[nmemb++];
	}
	free (mat);
	return (1);
}

static char	**ft_fill_mat(int argc, char **argv)
{
	char	**mat;
	size_t	i;
	size_t	j;
	
	if (!ft_search_spaces(argv))
		return (NULL);
	mat = ft_calloc(argc, sizeof(char *));
	if (!mat)
		return (NULL);
	i = 1;
	j = 0;
	while (argv[i])
		ft_strlcpy(&mat[j++], argv[i++]);
	return (mat);
}

char	**ft_check_params(int argc, char **argv)
{
	char	**str;

	if (!ft_check_next_char(argv))
		return (NULL);
	if (argc > 2)
		str = ft_fill_mat(argc, argv);
	else
		str = ft_split(argv[1], ' ');
	if (!str)
		return (NULL);
	if (!ft_check_dups(str))
	{
		ft_free_all(NULL, NULL, &str);
		return (NULL);
	}
	return (str);
}
