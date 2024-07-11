/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:51:30 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/12 12:04:34 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "time.h"

t_list	*fill_list(t_list *list_a, char **elements);
void	print_list(t_list *list_a, t_list *list_b);
t_list	*ft_swap(t_list *list, char c);
void	ft_push(t_list **list_src, t_list **list_dest, char c);
t_list	*ft_rotate(t_list *list, char c);
t_list	*ft_reverse_rotate(t_list *list, char c);
char	**ft_check_params(int argc, char **argv);
void	ft_free_all(t_list **list_a, t_list **list_b, char ***str);
char	**ft_fill_mat(int argc, char **argv);
t_list	*push_swap(t_list *list_a, t_list *list_b);
int		ft_check_list_sorted(t_list *list);
t_list	*ft_sort(t_list *list_a, t_list *list_b, size_t size);
t_list	*ft_sort_list(t_list *list_a, t_list *list_b);
char	*ft_search_min_max(int content, t_list *list);
int		ft_sort_sim(t_list *list_a, t_list *list_b);
size_t	ft_find_index(t_list *list, int target);
t_list	*ft_sort_three(t_list *list_a);
t_list	*ft_sort_list_back(t_list *list_a, t_list *list_b);
int		ft_sort_back_sim(t_list *list_a, t_list *list_b);
char	*ft_search_max_min(int content, t_list *list);

#endif