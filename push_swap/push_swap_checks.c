/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:10:51 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/02 17:11:40 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	ft_check_digits(char **mat)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (mat[++i])
	{
		j = 0;
		while (mat[i][j])
		{
			if ((mat[i][j] == '+' || mat[i][j] == '-') &&
				(mat[i][j + 1] == '+' || mat[i][j + 1] == '-'))
				return (0);
			else if (!ft_isdigit(mat[i][j]))
				return (0);
			j++;
		}
	}
	return (1);
}

char	**ft_check_params(int argc, char **argv)
{
	char	**str;
	int		i;
	size_t	j;
	
	if (!ft_check_digits(argv))
		return (NULL);
	i = 1;
	j = 0;
	if (argc > 2)
	{
		str = ft_calloc(argc, sizeof(char *));
		while (argv[i])
			ft_strlcpy(&str[j++], argv[i++]);
	}
	else
		str = ft_split(argv[1], ' ');
	if (!ft_check_dups(str))
	{
		ft_free_all(NULL, NULL, &str);
		return (NULL);
	}
	return (str);
}
