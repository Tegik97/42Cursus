/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:51:30 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/02 16:17:14 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZE
# define SIZE 100
#endif
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "time.h"

t_list		*fill_list(t_list *list_a, char **elements);
void		print_list(t_list *list_a, t_list *list_b);
t_list		*ft_swap(t_list *list);
void		ft_push(t_list **list_src, t_list **list_dest);
t_list		*ft_rotate(t_list *list);
t_list		*ft_reverse_rotate(t_list *list);
void		ft_print_error();
char		**ft_check_params(int argc, char **argv);
void	ft_free_all(t_list **list_a, t_list **list_b, char ***str);

#endif