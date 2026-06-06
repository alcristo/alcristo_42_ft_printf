/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:58:53 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/05 16:04:39 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	print_format(char c, va_list args)
{
	if (c == '%')
		return (ft_printf_putchar(c));
	else if (c == 'c')
		return (ft_printf_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_printf_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_printf_putmem(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_printf_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printf_putuns(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_printf_puthex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_printf_puthex(va_arg(args, unsigned int), 1));
	return (-1);
}

static int	check_flags(char const *format, va_list args)
{
	int	print_cs;

	print_cs = 0;
	if (ft_strchr("0-#+ .", *format) || ft_isdigit(*format))
		print_cs += ft_printf_flags(format, args);
	else
		print_cs += print_format(*format, args);
	return (print_cs);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		nc;
	int		print_cs;

	nc = 0;
	va_start(args, format);
	while (*format)
	{
		print_cs = 0;
		if (*format == '%')
		{
			format++;
			print_cs += check_flags(format, args);
			while (!ft_strchr("cspdiuxX%", *format))
				format++;
		}
		else
			print_cs += write(1, format, 1);
		if (print_cs == -1)
			return (-1);
		nc += print_cs;
		format++;
	}
	va_end(args);
	return (nc);
}
