/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_padtoleft.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 10:27:12 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/10 13:38:00 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	print_zeros(t_opts *opts, int chrs_n, int caps, int print_alt)
{
	int	nc;
	int	prc;

	nc = 0;
	if (opts->alt == 1 && print_alt == 1)
	{
		if (caps == 1)
			nc += write(opts->fd, "0X", 2);
		else
			nc += write(opts->fd, "0x", 2);
	}
	if (opts->precision < 0 && opts->right == 0 && opts->zero == 1)
		prc = opts->width - 2 * (print_alt > 0);
	else
	{
		if (opts->precision < chrs_n)
			opts->precision = chrs_n;
		prc = opts->precision;
	}
	while (prc-- > chrs_n)
		nc += write(opts->fd, "0", 1);
	return (nc);
}

static int	print_spaces(t_opts *opts, int chrs_n, int caps, int print_alt)
{
	int	nc;

	nc = 0;
	if (opts->width < chrs_n + 2 * (print_alt > 0))
		opts->width = chrs_n + 2 * (print_alt > 0);
	if (opts->precision < chrs_n)
		opts->precision = chrs_n;
	while (opts->width-- > opts->precision + 2 * (print_alt > 0))
		nc += write(opts->fd, " ", 1);
	return (nc + print_zeros(opts, chrs_n, caps, print_alt));
}

int	ft_printf_hex_padtoleft(t_opts *opts, int chrs_n, int caps, int print_alt)
{
	int	nc;

	nc = 0;
	if (opts->precision >= opts->width)
		nc += print_zeros(opts, chrs_n, caps, print_alt);
	else
	{
		if (opts->right == 0)
		{
			if (opts->precision < 0 && opts->zero == 1)
				nc += print_zeros(opts, chrs_n, caps, print_alt);
			else
				nc += print_spaces(opts, chrs_n, caps, print_alt);
		}
		else
			nc += print_zeros(opts, chrs_n, caps, print_alt);
	}
	return (nc);
}
