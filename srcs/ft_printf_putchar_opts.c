/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar_opts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:57:18 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/10 13:30:58 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf_putchar_opts(int c, t_opts *opts)
{
	char	chr;
	int		nc;

	chr = (char)c;
	nc = 0;
	if (opts->right == 0)
	{
		while (opts->width-- > 1)
			nc += write(opts->fd, " ", 1);
	}
	nc += write(1, &chr, 1);
	if (opts->right == 1)
	{
		while (opts->width-- > 1)
			nc += write(opts->fd, " ", 1);
	}
	return (nc);
}
