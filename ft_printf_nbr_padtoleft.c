/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_padtoleft.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:40:14 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/06 15:18:50 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_zeros(t_opts *opts, int prc, int chrs_n, int plus)
{
	int	nc;

	nc = 0;
	if (plus == 1)
	{
		if (opts->plus == 1)
			nc += write(1, "+", 1);
		else if (opts->space == 1)
			nc += write(1, " ", 1);
	}
	else
		nc += (write(1, "-", 1));
	while (prc-- > chrs_n)
		nc += write(1, "0", 1);
	return (nc);
}

/*static int	print_spaces(t_opts *opts, int prc, int chrs_n, int plus)
{
	int	nc;

	nc = 0;
	while (prc-- > chrs_n)
		nc += write(1, " ", 1);
	if (plus == 1)
	{
		if (opts->plus == 1)
			nc += write(1, "+", 1);
		else if (opts->space == 1)
			nc += write(1, " ", 1);
	}
	else
		nc += (write(1, "-", 1));
	return (nc);
}*/

/*static int	zero_flag(t_opts *opts, int chrs_n, int plus, int sign)
{
	int	nc;

	nc = 0;
	if (opts->precision < chrs_n)
	{
		while (opts->width-- > opts->precision + sign)
			nc += write(1, " ", 1);
		nc += print_zeros(opts, opts->precision, chrs_n, plus);
	}
	else
		nc += print_zeros(opts, opts->width, chrs_n, plus);
	return (nc);
}*/

int	ft_printf_nbr_padtoleft(t_opts *opts, int chrs_n, int plus, int sign)
{
	int	nc;
//	int	cond;

	nc = 0;
//	cond = opts->zero == 1 && opts->precision < chrs_n;
	if (opts->precision >= opts->width)
		nc += print_zeros(opts, opts->precision, chrs_n, plus);
	else
	{
		if (opts->right == 0)
		{
			if ((opts->zero == 0) || chrs_n > opts->precision)
			{
				while (opts->width-- > opts->precision + sign)
					nc += write(1, " ", 1);
				nc += print_zeros(opts, opts->precision, chrs_n, plus);
			}
			else
				nc += print_zeros(opts, opts->width - sign, chrs_n, plus);
		}
		else
			nc += print_zeros(opts, opts->precision, chrs_n, plus);
	}
	return (nc);
}
