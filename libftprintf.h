/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 09:50:32 by alcristo          #+#    #+#             */
/*   Updated: 2026/05/30 15:58:24 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
int		ft_printf_putchar(char c);
int		ft_printf_putstr(char *s);
int		ft_printf_putnbr(int nbr);
int		ft_printf_putuns(size_t n);
int		ft_printf_puthex(int nbr, int caps);
int		ft_printf_putmem(void *memadd);

#endif
