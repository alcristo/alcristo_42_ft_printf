/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putflt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 09:08:21 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/23 11:01:39 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_printf_putflt_print(long z, long r, int sign)
{
	size_t	nc;

	nc = 0;
	if (sign < 0)
		nc += write(1, "-", 1);
	nc += ft_printf_putuns(z);
	nc += write(1, ".", 1);
	nc += ft_printf_putuns(r);
	return (nc);
}

int	ft_printf_putflt(double f)
{
	long	z;
	long	r;
	int		sign;

/*	if ((long)f > LONG_MAX)
		return (write(opts->fd, "Inf", 3));
	if ((long)f < LONG_MIN)
		return (write(opts->fd, "-Inf", 4));*/
	sign = 1;
	if (f < 0)
	{
		sign = -1;
		f *= -1;
	}
	z = f / 1;
	r = (((f - z) * ft_power(10, 7) + 5) / 10);
	if (r >= ft_power(10, 7))
	{
		r -= ft_power(10, 7);
		z += 1;
	}
	return (ft_printf_putflt_print(z, r, sign));
}
