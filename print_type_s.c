

#include "ft_printf.h"

int	print_type_s(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return(i + 6);
	}
	while (str[i])
	{
		ft_putchar((int)str[i]);  //maybe wrong
		i++;
	}
	return (i);
}