/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:26:26 by ybollen           #+#    #+#             */
/*   Updated: 2024/03/20 13:26:32 by ybollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type_x(unsigned int n, int hexa)
{
	char	c;
	int		len;

	len = 0;
	if (n >= 16)
	{
		len += print_type_x(n / 16, hexa);
		len += print_type_x(n % 16, hexa);
	}
	else if (n <= 9)
	{
		c = n + '0';
		len += ft_putchar(c);
	}
	else
	{
		if (hexa == 'X')
			c = n - 10 + '0' + 17;
		else
			c = n - 10 + '0' + 49;
		len += ft_putchar(c);
	}
	return (len);
}
