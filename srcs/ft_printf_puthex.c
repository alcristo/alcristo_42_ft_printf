/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 09:57:31 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/07 11:42:32 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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
