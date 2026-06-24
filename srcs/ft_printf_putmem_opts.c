/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putmem_opts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:41:13 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/23 09:54:09 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	print_hex(size_t nbr, t_opts *opts)
{
	char	*base;
	char	c;
	int		nc;

	if (!nbr)
		return (write(opts->fd, "(nil)", 5));
	nc = 0;
	base = "0123456789abcdef";
	if (nbr > 15)
		nc += print_hex(nbr / 16, opts);
	c = base[nbr % 16];
	nc += write(opts->fd, &c, 1);
	return (nc);
}

static int	print_zeros(size_t addr, t_opts *opts, int prc, int chrs_n)
{
	int	nc;

	if (!addr)
		return (0);
	nc = 0;
	if (opts->plus == 1)
		nc += write(opts->fd, "+", 1);
	else if (opts->space == 1)
		nc += write(opts->fd, " ", 1);
	nc += write(1, "0x", 2);
	while (--prc > chrs_n)
		nc += write(opts->fd, "0", 1);
	return (nc);
}

static int	pad_to_left(size_t addr, t_opts *opts, int chrs_n, int sign)
{
	int	nc;

	nc = 0;
	if (opts->width < opts->precision)
		nc += print_zeros(addr, opts, opts->precision, chrs_n);
	else
	{
		if (opts->right == 0)
		{
			if (opts->precision < 0 && opts->zero == 1)
				nc += print_zeros(addr, opts, opts->width, chrs_n);
			else
			{
				while (opts->width-- > opts->precision + (2 + sign) * !(!addr))
					nc += write(opts->fd, " ", 1);
				nc += print_zeros(addr, opts, opts->precision, chrs_n);
			}
		}
		else
			nc += print_zeros(addr, opts, opts->precision, chrs_n);
	}
	return (nc);
}

static int	charmem(size_t addr)
{
	int	chrs_n;

	if (!addr)
		return (0);
	chrs_n = 1;
	while (addr > 15)
	{
		chrs_n++;
		addr /= 16;
	}
	return (chrs_n);
}

int	ft_printf_putmem_opts(void *memadd, t_opts *opts)
{
	int		nc;
	int		sign;
	int		chrs_n;
	size_t	addr;

	addr = (size_t)memadd;
	chrs_n = charmem(addr);
	sign = (opts->space == 1 || opts->plus == 1);
	if (opts->width < chrs_n + (2 * (chrs_n > 0)) + sign)
		opts->width = chrs_n + (2 * (chrs_n > 0)) + sign;
	if (!addr)
		opts->precision = 5;
	if (opts->precision < chrs_n + 2)
		opts->precision = chrs_n;
	nc = 0;
	nc += pad_to_left(addr, opts, chrs_n, sign);
	nc += print_hex(addr, opts);
	if (opts->right == 1)
	{
		opts->width -= nc;
		while (opts->width-- > 0)
			nc += write(opts->fd, " ", 1);
	}
	return (nc);
}
