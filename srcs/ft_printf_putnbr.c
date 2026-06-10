/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 11:54:39 by alcristo          #+#    #+#             */
/*   Updated: 2026/05/30 16:46:06 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf_putnbr(int nbr)
{
	long	nl;
	int		nc;
	char	c;

	if (nbr == 0)
		return (write(1, "0", 1));
	nl = (long)nbr;
	nc = 0;
	if (nl < 0)
	{
		nc += write(1, "-", 1);
		nl *= -1;
	}
	if (nl > 9)
		nc += ft_printf_putnbr(nl / 10);
	c = nl % 10 + '0';
	nc += write(1, &c, 1);
	return (nc);
}
