/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr_opts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:31:14 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/23 09:53:26 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	print_nbr(int nbr, t_opts *opts)
{
	char	c;
	long	n;
	int		nc;

	nc = 0;
	n = (long)nbr;
	if (n < 0)
		n *= -1;
	if (n > 9)
		nc += print_nbr(n / 10, opts);
	c = n % 10 + '0';
	nc += write(opts->fd, &c, 1);
	return (nc);
}

static int	charnbr(int nbr, t_opts *opts)
{
	int		chrs_n;
	long	n;

	if (nbr == 0 && opts->precision == 0)
		return (0);
	chrs_n = 1;
	n = (long)nbr;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		chrs_n++;
		n /= 10;
	}
	return (chrs_n);
}

int	ft_printf_putnbr_opts(int nbr, t_opts *opts)
{
	int		nc;
	int		chrs_n;
	int		sign;

	chrs_n = charnbr(nbr, opts);
	nc = 0;
	sign = (opts->plus == 1 || opts->space == 1 || nbr < 0);
	nc += ft_printf_nbr_padtoleft(opts, chrs_n, (nbr >= 0), sign);
	if (chrs_n > 0)
		nc += print_nbr(nbr, opts);
	if (opts->right == 1 && opts->width > nc)
	{
		opts->width -= nc;
		while (opts->width-- > 0)
			nc += write(opts->fd, " ", 1);
	}
	return (nc);
}
