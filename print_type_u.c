



#include "ft_printf.h"

void	print_type_u(unsigned int n, int *len)
{
	char	c;

	if (n >= 10)
	{
		print_type_u(n / 10, len);
		print_type_u(n % 10, len);
	}
	else
	{
		*len++;
		c = n + '0';
		ft_putchar(c);
	}
}