/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_padtoleft.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:40:14 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/10 13:35:24 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	print_zeros(t_opts *opts, int chrs_n, int plus, int sign)
{
	int	nc;
	int	prc;

	nc = 0;
	if (plus == 1)
	{
		if (opts->plus == 1)
			nc += write(opts->fd, "+", 1);
		else if (opts->space == 1)
			nc += write(opts->fd, " ", 1);
	}
	else
		nc += (write(opts->fd, "-", 1));
	if (opts->zero == 1 && opts->precision < 0 && opts->right == 0)
		prc = opts->width - sign;
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

static int	print_spaces(t_opts *opts, int chrs_n, int plus, int sign)
{
	int	nc;

	nc = 0;
	if (opts->width < chrs_n + sign)
		opts->width = chrs_n + sign;
	if (opts->precision < chrs_n)
		opts->precision = chrs_n;
	while (opts->width-- > opts->precision + sign)
		nc += write(opts->fd, " ", 1);
	return (nc + print_zeros(opts, chrs_n, plus, sign));
}

int	ft_printf_nbr_padtoleft(t_opts *opts, int chrs_n, int plus, int sign)
{
	int	nc;

	nc = 0;
	if (opts->precision >= opts->width)
		nc += print_zeros(opts, chrs_n, plus, sign);
	else
	{
		if (opts->right == 0)
		{
			if (opts->precision < 0 && opts->zero == 1)
				nc += print_zeros(opts, chrs_n, plus, sign);
			else
				nc += print_spaces(opts, chrs_n, plus, sign);
		}
		else
			nc += print_zeros(opts, chrs_n, plus, sign);
	}
	return (nc);
}
