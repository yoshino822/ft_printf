/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:27:36 by ybollen           #+#    #+#             */
/*   Updated: 2024/03/20 13:27:38 by ybollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type_u(unsigned int n)
{
	char	c;
	int		len;

	len = 0;
	if (n >= 10)
	{
		len += print_type_u(n / 10);
		len += print_type_u(n % 10);
	}
	else
	{
		c = n + '0';
		len += ft_putchar(c);
	}
	return (len);
}
