/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putuns_opts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 10:19:30 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/23 09:54:51 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	print_uns(unsigned int nbr, t_opts *opts)
{
	char	c;
	int		nc;

	nc = 0;
	if (nbr > 9)
		nc += print_uns(nbr / 10, opts);
	c = nbr % 10 + '0';
	nc += write(opts->fd, &c, 1);
	return (nc);
}

static int	print_zeros(t_opts *opts, int prc, int chrs_n)
{
	int	nc;

	if (chrs_n >= opts->precision)
		opts->precision = chrs_n;
	nc = 0;
	while (prc-- > chrs_n)
		nc += write(opts->fd, "0", 1);
	return (nc);
}

static int	pad_to_left(t_opts *opts, int chrs_n)
{
	int	nc;

	nc = 0;
	if (opts->precision >= opts->width)
		nc += print_zeros(opts, opts->precision, chrs_n);
	else
	{
		if (opts->right == 0)
		{
			if (opts->precision < 0 && opts->zero == 1)
				nc += print_zeros(opts, opts->width, chrs_n);
			else
			{
				if (opts->precision < chrs_n)
					opts->precision = chrs_n;
				while (opts->width-- > opts->precision)
					nc += write(opts->fd, " ", 1);
				nc += print_zeros(opts, opts->precision, chrs_n);
			}
		}
		else
			nc += print_zeros(opts, opts->precision, chrs_n);
	}
	return (nc);
}

static int	charuns(unsigned int nbr, t_opts *opts)
{
	int	chrs_n;

	if (nbr == 0 && opts->precision == 0)
		return (0);
	chrs_n = 1;
	while (nbr > 9)
	{
		chrs_n++;
		nbr /= 10;
	}
	return (chrs_n);
}

int	ft_printf_putuns_opts(unsigned int nbr, t_opts *opts)
{
	int		nc;
	int		chrs_n;

	chrs_n = charuns(nbr, opts);
	nc = 0;
	if (chrs_n >= opts->width)
		opts->width = chrs_n;
	nc += pad_to_left(opts, chrs_n);
	if (chrs_n > 0)
		nc += print_uns(nbr, opts);
	if (opts->right == 1 && opts->width > nc)
	{
		opts->width -= nc;
		while (opts->width-- > 0)
			nc += write(opts->fd, " ", 1);
	}
	return (nc);
}
