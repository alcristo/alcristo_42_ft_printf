/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthex_opts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 09:57:31 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/06 13:22:08 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex(unsigned int nbr, int caps)
{
	char	*base;
	char	c;
	int		nc;

	nc = 0;
	if (caps == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	c = 0;
	if (nbr > 15)
		nc += print_hex(nbr / 16, caps);
	c = base[nbr % 16];
	nc += write(1, &c, 1);
	return (nc);
}

static int	print_zeros(t_opts *opts, int print_alt, int chrs_n, int caps)
{
	int	nc;
	int	prc;
	int	cond;

	nc = 0;
	prc = 0;
	if (opts->alt == 1 && print_alt == 1)
	{
		if (caps == 1)
			nc += write(1, "0X", 2);
		else
			nc += write(1, "0x", 2);
	}
	cond = (opts->zero == 0 || chrs_n < opts->precision);
	if (opts->precision < opts->width && opts->right == 0 && cond == 0)
		prc = opts->width;
	else
		prc = opts->precision;
	while (prc-- > chrs_n)
		nc += write(1, "0", 1);
	return (nc);
}

static int	pad_to_left(t_opts *opts, int chrs_n, int caps, int print_alt)
{
	int	nc;

	nc = 0;
	if (opts->precision >= opts->width)
		nc += print_zeros(opts, print_alt, chrs_n, caps);
	else
	{
		if (opts->right == 0)
		{
			if (opts->zero == 0 || chrs_n < opts->precision)
			{
				while (opts->width-- > opts->precision)
					nc += write(1, " ", 1);
				nc += print_zeros(opts, print_alt, chrs_n, caps);
			}
			else
				nc += print_zeros(opts, print_alt, chrs_n, caps);
		}
		else
			nc += print_zeros(opts, print_alt, chrs_n, caps);
	}
	return (nc);
}

static int	charhex(unsigned int nbr, t_opts *opts)
{
	int	chrs_n;

	if (nbr == 0 && opts->precision == 0)
		return (0);
	chrs_n = 1;
	while (nbr > 15)
	{
		chrs_n++;
		nbr /= 16;
	}
	return (chrs_n);
}

int	ft_printf_puthex_opts(unsigned int nbr, int caps, t_opts *opts)
{
	int	nc;
	int	chrs_n;
	int	print_alt;

	chrs_n = charhex(nbr, opts);
	nc = 0;
	print_alt = 1;
	if (chrs_n >= opts->width)
		opts->width = chrs_n;
	if (chrs_n >= opts->precision)
		opts->precision = chrs_n;
	if (nbr == 0)
		print_alt = 0;
	nc += pad_to_left(opts, chrs_n, caps, print_alt);
	if (chrs_n > 0)
		nc += print_hex(nbr, caps);
	if (opts->right == 1)
	{
		opts->width -= nc;
		while (opts->width-- > 0)
			nc += write(1, " ", 1);
	}
	return (nc);
}
