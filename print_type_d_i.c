/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:25:57 by ybollen           #+#    #+#             */
/*   Updated: 2024/03/20 13:25:59 by ybollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type_d_i(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		len += 11;
		return (len);
	}
	else if (n < 0)
	{
		len += ft_putchar('-');
		len += print_type_d_i(-n);
	}
	else if (n >= 10)
	{
		len += print_type_d_i(n / 10);
		len += ft_putchar((n % 10) + '0');
	}
	else
	{
		len += ft_putchar(n + '0');
	}
	return (len);
}
