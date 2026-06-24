/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:09:18 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/23 10:48:53 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_opts
{
	int		alt;
	int		zero;
	int		right;
	int		space;
	int		plus;
	int		width;
	int		precision;
	int		fd;
}			t_opts;
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
void	*ft_memset(void *s, int c, size_t n);
long	ft_power(long base, long exp);		
int		ft_printf(char const *format, ...);
int		ft_printf_putnbr(int nbr);
int		ft_printf_putuns(unsigned int nbr);
int		ft_printf_puthex(unsigned int nbr, int caps);
int		ft_printf_putchar(int c);
int		ft_printf_putstr(char *str);
int		ft_printf_putmem(void *memadd);
int		ft_printf_putflt(double f);
int		ft_printf_flags(char const *format, va_list args);
int		ft_printf_putnbr_opts(int nbr, t_opts *opts);
int		ft_printf_nbr_padtoleft(t_opts *opts, int chrs_n, int plus, int sign);
int		ft_printf_putuns_opts(unsigned int nbr, t_opts *opts);
int		ft_printf_puthex_opts(unsigned int nbr, int caps, t_opts *opts);
int		ft_printf_hex_padtoleft(t_opts *opts, int chrs_n,
			int caps, int print_alt);
int		ft_printf_putchar_opts(int c, t_opts *opts);
int		ft_printf_putstr_opts(char *str, t_opts *opts);
int		ft_printf_putmem_opts(void *memadd, t_opts *opts);
int		ft_printf_putflt_opts(double f, t_opts *opts);

#endif
