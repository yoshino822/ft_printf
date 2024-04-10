/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:26:57 by ybollen           #+#    #+#             */
/*   Updated: 2024/03/20 13:26:59 by ybollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_putchar(char c);
int	print_type_p(unsigned long long n);
int	print_type_d_i(int n);
int	print_type_u(unsigned int n);
int	print_type_x(unsigned int n, int hexa);

int	ft_printf(const char *format, ...);
int	print_type_s(char *str);

#endif
