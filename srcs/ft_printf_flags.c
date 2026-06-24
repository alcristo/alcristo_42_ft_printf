/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:53:09 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/23 10:49:59 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	print_format(char c, va_list args, t_opts *opts)
{
	if (c == '%')
		return (write(opts->fd, "%", 1));
	else if (c == 'c')
		return (ft_printf_putchar_opts(va_arg(args, int), opts));
	else if (c == 's')
		return (ft_printf_putstr_opts(va_arg(args, char *), opts));
	else if (c == 'p')
		return (ft_printf_putmem_opts(va_arg(args, void *), opts));
	else if (c == 'd' || c == 'i')
		return (ft_printf_putnbr_opts(va_arg(args, int), opts));
	else if (c == 'u')
		return (ft_printf_putuns_opts(va_arg(args, unsigned int), opts));
	else if (c == 'x')
		return (ft_printf_puthex_opts(va_arg(args, unsigned int), 0, opts));
	else if (c == 'X')
		return (ft_printf_puthex_opts(va_arg(args, unsigned int), 1, opts));
	else if (c == 'f')
		return (ft_printf_putflt_opts(va_arg(args, double), opts));
	return (-1);
}

static void	flags(char const *format, t_opts *opts)
{
	opts->alt = 0;
	opts->zero = 0;
	opts->right = 0;
	opts->plus = 0;
	opts->space = 0;
	while (ft_strchr("#0- +", *format))
	{
		if (*format == '#' && opts->alt == 0)
			opts->alt = 1;
		if (*format == '0' && opts->zero == 0)
			opts->zero = 1;
		if (*format == '-' && opts->right == 0)
			opts->right = 1;
		if (*format == ' ' && opts->space == 0)
			opts->space = 1;
		if (*format == '+' && opts->plus == 0)
			opts->plus = 1;
		format++;
	}
}

static void	minimum_width(char const *format, t_opts *opts)
{
	if (ft_isdigit(*format))
	{
		opts->width = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	else
		opts->width = 0;
	if (*format == '.')
	{
		format++;
		opts->precision = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	else
		opts->precision = -1;
	if (*format == '/')
	{
		format++;
		opts->fd = ft_atoi(format);
	}
	else
		opts->fd = 1;
}

static int	free_flags(t_opts *opts)
{
	free(opts);
	return (-1);
}

int	ft_printf_flags(char const *format, va_list args)
{
	t_opts	*opts;
	int		print_cs;

	opts = malloc(sizeof(t_opts));
	if (!opts)
		return (-1);
	flags(format, opts);
	while (ft_strchr("#0- +", *format) && *(format))
		format++;
	if (!format)
		return (free_flags(opts));
	minimum_width(format, opts);
	while ((ft_isdigit(*format) || ft_strchr("./", *format)) && *(format))
		format++;
	if (!format)
		return (free_flags(opts));
	if (ft_strchr("cspdiuxXf%", *format))
		print_cs = print_format(*format, args, opts);
	else
		print_cs = -1;
	free(opts);
	return (print_cs);
}
