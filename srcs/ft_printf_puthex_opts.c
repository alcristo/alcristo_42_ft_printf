/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthex_opts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 09:57:31 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/23 09:54:21 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	print_hex(unsigned int nbr, int caps, t_opts *opts)
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
		nc += print_hex(nbr / 16, caps, opts);
	c = base[nbr % 16];
	nc += write(opts->fd, &c, 1);
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
	if (nbr == 0 || opts->alt == 0)
		print_alt = 0;
	nc += ft_printf_hex_padtoleft(opts, chrs_n, caps, print_alt);
	if (chrs_n > 0)
		nc += print_hex(nbr, caps, opts);
	if (opts->right == 1)
	{
		opts->width -= nc;
		while (opts->width-- > 0)
			nc += write(opts->fd, " ", 1);
	}
	return (nc);
}
