/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar_opts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:57:18 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/06 16:10:05 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf_putchar_opts(int c, t_opts *opts)
{
	char	chr;
	int		nc;

	chr = (char)c;
	nc = 0;
	if (opts->right == 0)
	{
		while (opts->width-- > 1)
			nc += write(1, " ", 1);
	}
	nc += write(1, &chr, 1);
	if (opts->right == 1)
	{
		while (opts->width-- > 1)
			nc += write(1, " ", 1);
	}
	return (nc);
}
