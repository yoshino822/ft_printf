


#include "ft_printf.h"

void	print_type_x(unsigned int n, int *len, int hexa)
{
	char	c;

	if (n >= 16)
	{
		print_type_x(n / 16, len, hexa);
		print_type_x(n % 16, len, hexa);
	}
	else if (n <= 9)  //base = "0123456789abcdef";
	{
		*len++;
		c = n + '0'; // change to char number;
		ft_putchar(c);
	}
	else // if (10 < n < 16)
	{
		*len++;
		if (hexa == 'X')// conversion either to x or X
			c = n - 10 + '0' + 17;
		else
			c = n - 10 + '0' + 49;
		ft_putchar(c);
	} //if n = 12 (hex C) -> n - 10(excl 0-9) + '0'(to convert to char) + 17(from '0' to uppercase 'C'=17) + 32(to 'c')
}