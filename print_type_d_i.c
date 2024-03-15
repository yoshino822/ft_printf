


#include "ft_printf.h"

void	print_type_d_i(int n, int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len += 11;
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		print_type_d_i(-n, len);
	}
	else if (n >= 10)
	{
		print_type_d_i(n / 10, len);
		ft_putchar((n % 10) + '0');
	}
	else
	{
		ft_putchar(n + '0');
	}
}