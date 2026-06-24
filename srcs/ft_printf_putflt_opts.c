/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putflt_opts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:21:34 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/24 09:18:26 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>

static int	print_nbr(long n, t_opts *opts)
{
	char	c;
	int		nc;

	nc = 0;
	if (n > 9)
		nc += print_nbr(n / 10, opts);
	c = n % 10 + '0';
	nc += write(opts->fd, &c, 1);
	return (nc);
}

static int	print_sign(double f, t_opts *opts)
{
	if (f < 0)
		return(write(opts->fd, "-", 1));
	else if (opts->plus == 1)
		return(write(opts->fd, "+", 1));
	else if (opts->space == 1)
		return(write(opts->fd, " ", 1));
	return (0);
}

static int	print_float(double f, int sign, t_opts *opts)
{
	int		nc;
	long	z;
	long	r;

	nc = 0;
	if (sign)
		nc += print_sign(f, opts);
	if (f < 0)
		f *= -1;
	z = f / 1;
	r = ((f - z) * ft_power(10, opts->precision + 1) + 5) / 10;
	if (r >= ft_power(10, opts->precision + 1))
	{
		r -= ft_power(10, opts->precision + 1);
		z++;
	}
	nc += print_nbr(z, opts);
	if (opts->precision != 0)
		nc += write(opts->fd, ".", 1);
	nc += print_nbr(r, opts);
	return (nc);
}

static int	charnbr(double f, int sign, t_opts *opts)
{
	int		chrs_n;
	long	z;

	if (f == 0 && opts->precision == 0)
		return (0);
	chrs_n = 1;
	if (sign)
		chrs_n++;
	chrs_n += opts->precision;
	if (opts->precision != 0)
		chrs_n++;
	z = f / 1;
	if (z < 0)
		z *= -1;
	while (z > 9)
	{
		chrs_n++;
		z /= 10;
	}
	return (chrs_n);
}

int	ft_printf_putflt_opts(double f, t_opts *opts)
{
	int	nc;
	int	chrs_n;
	int	sign;

	if (opts->precision > 13)
		opts->precision = 13;
	if (opts->precision < 0)
		opts->precision = 6;
	sign = (opts->plus == 1 || opts->space == 1 || f < 0);
	chrs_n = charnbr(f, sign, opts);
	nc = 0;
	if (opts->right == 0)
	{
		while (opts->width-- > chrs_n + sign)
			nc += write(opts->fd, " ", 1);
	}
	nc += print_float(f, sign, opts);
	if (opts->right == 1)
	{
		opts->width -= nc;
		while (opts->width-- > 0)
			nc += write(opts->fd, " ", 1);
	}
	return (nc);
}
