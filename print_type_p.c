


#include "ft_printf.h"

void	print_type_p(unsigned long int n, int *len)
{
	char	c;

	write(1, "0x", 2);
	*len += 2;
	if (n >= 16)
	{
		print_type_p(n / 16, len);
		print_type_p(n % 16, len);
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
		c = n - 87;// conversion from hexa to char (e.g. hexa c to char c)
		ft_putchar(c);
	} // if n = 12 (hex C) -> n - 10(excl 0-9) + '0'(to convert to char) + 17('0'+17= C in char) + 32(to char c)
}
