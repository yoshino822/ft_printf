/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:25:19 by ybollen           #+#    #+#             */
/*   Updated: 2024/03/20 13:25:23 by ybollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char format_type, va_list args)
{
	int	len;

	len = 0;
	if (format_type == 'c')
		len += ft_putchar((char)va_arg(args, int));
	else if (format_type == 's')
	{
		len += print_type_s(va_arg(args, char *));
	}
	else if (format_type == 'p')
		len += print_type_p(va_arg(args, size_t));
	else if (format_type == 'd' || format_type == 'i')
		len += print_type_d_i(va_arg(args, int));
	else if (format_type == 'u')
		len += print_type_u(va_arg(args, unsigned int));
	else if (format_type == 'x')
		len += print_type_x(va_arg(args, unsigned int), 'x');
	else if (format_type == 'X')
		len += print_type_x(va_arg(args, unsigned int), 'X');
	else if (format_type == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += print_format(*format, args);
		}
		else
		{
			len += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	int	count;

	count = ft_printf("%x\n", 42);
	ft_printf("The chars written are %d\n", count);
	count = printf("%x\n", 42);
	printf("The chars written are %d\n", count);
	return (0);
}*/
