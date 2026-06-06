/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 09:57:31 by alcristo          #+#    #+#             */
/*   Updated: 2026/05/31 10:47:51 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int	ft_putnbr_hex_write(unsigned int nbr, char *base)
{
	char	c;
	int		nc;

	c = 0;
	nc = 0;
	if (nbr > 15)
		nc += ft_putnbr_hex_write(nbr / 16, base);
	c = base[nbr % 16];
	nc += write(1, &c, 1);
	return (nc);
}*/

int	ft_printf_puthex(unsigned int nbr, int caps)
{
	char	*base;
	char	c;
	int		nc;

	if (nbr == 0)
		return (write(1, "0", 1));
	if (caps == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	c = 0;
	nc = 0;
	if (nbr > 15)
		nc += ft_printf_puthex(nbr / 16, caps);
	c = base[nbr % 16];
	nc += write(1, &c, 1);
	return (nc);
}
