/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putuns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 09:44:35 by alcristo          #+#    #+#             */
/*   Updated: 2026/05/30 17:05:08 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf_putuns(unsigned int n)
{
	char	c;
	int		nc;

	if (n == 0)
		return (write(1, "0", 1));
	nc = 0;
	if (n > 9)
		nc += ft_printf_putuns(n / 10);
	c = n % 10 + '0';
	nc += ft_printf_putchar(c);
	return (nc);
}
