/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:13:33 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/14 20:17:48 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "libft.h"

char	**ft_check_params(int argc, char **argv);
t_list	*fill_list(t_list *list, char **elements);
int		ft_check_list_sorted(t_list *list);
t_list	*ft_swap(t_list *list, char c);
void	ft_push(t_list **list_src, t_list **list_dest, char c);
t_list	*ft_rotate(t_list *list, char c);
t_list	*ft_reverse_rotate(t_list *list, char c);
void	ft_free_all(t_list **list_a, t_list **list_b, char ***str);
t_list	*push_swap(t_list *list_a);
char	**ft_fill_mat(int argc, char **argv);
void	print_list(t_list *list_a, t_list *list_b);

#endif