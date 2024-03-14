//
// Created by PC on 14-03-24.
//
#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}