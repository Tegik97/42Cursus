/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:10:51 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/05 18:06:44 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_limits(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) > ft_atoi("2147483647"))
			return (0);
		else if (ft_atoi(str[i]) < ft_atoi("-2147483648"))
			return (0);
		i++;
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
			else if (!ft_isdigit(str[i][j]) && str[i][j] != '+' &&
					str[i][j] != '-' && str[i][j] != ' ')
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

char	**ft_check_params(int argc, char **argv)
{
	char	**str;

	if (!ft_check_next_char(argv))
		return (NULL);
	str = ft_fill_mat(argc, argv);
	if (!str)
		return (NULL);
	if (!ft_check_dups(str) || !ft_check_limits(str))
	{
		ft_free_all(NULL, NULL, &str);
		return (NULL);
	}
	return (str);
}
