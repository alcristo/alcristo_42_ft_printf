/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:58:53 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/23 10:45:14 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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
	else if (c == 'f')
		return (ft_printf_putflt(va_arg(args, double)));
	return (-1);
}

static int	check_flags(char const *format, va_list args)
{
	int	print_cs;

	print_cs = 0;
	if (ft_strchr("0-#+ ./", *format) || ft_isdigit(*format))
		print_cs += ft_printf_flags(format, args);
	else
		print_cs += print_format(*format, args);
	return (print_cs);
}

static int	iter_format(char const *format, va_list args)
{
	int		nc;
	int		print_cs;

	nc = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0')
				return (-1);
			format++;
			print_cs = check_flags(format, args);
			if (print_cs == -1)
				return (-1);
			while (!ft_strchr("cspdiuxXf%", *format))
				format++;
		}
		else
			print_cs = write(1, format, 1);
		if (print_cs == -1)
			return (-1);
		nc += print_cs;
		format++;
	}
	return (nc);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		nc;

	if (!format)
		return (-1);
	va_start(args, format);
	nc = iter_format(format, args);
	va_end(args);
	return (nc);
}

/*
Consejo de Alberto:
Añadir flag para descriptor de archivo.
Al parecer vendra bien para el push swap
*/
