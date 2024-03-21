/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:49:00 by mchiaram          #+#    #+#             */
/*   Updated: 2024/01/29 17:59:33 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
size_t	ft_digitcount(long int n, char c);
int		ft_putptr(void *ptr);
int		ft_ptrdigitcount(uintptr_t n);
int		ft_printnbr(int nbr, char c);

#endif