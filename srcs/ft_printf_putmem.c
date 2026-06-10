/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putmem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:17:12 by alcristo          #+#    #+#             */
/*   Updated: 2026/05/31 11:51:05 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_printf_putmemhex(size_t n)
{
	char	*base;
	char	c;
	int		nc;

	nc = 0;
	base = "0123456789abcdef";
	if (n > 15)
		nc += ft_printf_putmemhex(n / 16);
	c = base[n % 16];
	nc += write(1, &c, 1);
	return (nc);
}

int	ft_printf_putmem(void *memadd)
{
	size_t	addr;
	int		nc;

	if (!memadd)
		return (write(1, "(nil)", 5));
	addr = (size_t)memadd;
	nc = write(1, "0x", 2);
	return (nc + ft_printf_putmemhex(addr));
}
