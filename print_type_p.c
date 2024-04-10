/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:27:22 by ybollen           #+#    #+#             */
/*   Updated: 2024/03/20 13:27:26 by ybollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long long n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += print_ptr(n / 16);
		len += print_ptr(n % 16);
	}
	else if (n >= 10)
		len += ft_putchar(n - 10 + 'a');
	else
		len += ft_putchar(n + '0');
	return (len);
}

int	print_type_p(unsigned long long n)
{
	int	len;

	len = 0;
	if (!n)
	{
		len += print_type_s("(nil)");
		return (len);
	}
	else if (n)
	{
		write(1, "0x", 2);
		len += 2;
		len += print_ptr(n);
	}
	return (len);
}
