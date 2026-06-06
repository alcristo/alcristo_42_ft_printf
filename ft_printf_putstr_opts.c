/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr_opts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:51:26 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/06 14:56:10 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_str(char *s, int prc)
{
	int		nc;

	if (!s)
		return (write(1, "(null)", 6));
	nc = 0;
	while (s[nc] && prc)
	{
		nc += write(1, &s[nc], 1);
		prc--;
	}
	return (nc);
}

static int	get_len(char *s, t_opts *opts)
{
	int	len;

	if (!s)
	{
		if (opts->precision >= 0 && opts->precision < 6)
			return (0);
		else
			return (6);
	}
	len = 0;
	while (s[len])
		len++;
	if (opts->precision < 0)
		opts->precision = len;
	if (len < opts->precision)
		return (len);
	return (opts->precision);
}

int	ft_printf_putstr_opts(char *s, t_opts *opts)
{
	int	nc;
	int	len;

	nc = 0;
	len = get_len(s, opts);
	if (opts->right == 0)
	{
		while (opts->width-- > len)
			nc += write(1, " ", 1);
	}
	if (len > 0)
		nc += fill_str(s, len);
	if (opts->right == 1)
	{
		opts->width -= nc;
		while (opts->width-- > 0)
			nc += write(1, " ", 1);
	}
	return (nc);
}
