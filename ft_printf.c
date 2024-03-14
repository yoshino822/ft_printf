


#include "ft_printf.h"
#include <stdio.h>

void	print_c(int c)
{
	ft_putchar(c); // maybe '&' is needed
}

int	print_s(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		ft_putchar((int)str[i]);
		count++;  // maybe ++count;
		i++;  // maybe ++i;
	}
	return (count);
}

int	print_num(long n, int base)
{
	int	count;
	char	*hexa_small;
	char	*hexa_upper;

	hexa_small = "0123456789abcdef";
	hexa_upper = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_putchar("-");
		return (print_num(-n, base) + 1); // -n to to make num positive;
	}
	else if (n < base)
		if(n == 'x')
			return (ft_putchar(hexa_small[n]));
		else
			return (ft_putchar(hexa_upper[n]));
	else
	{
		count = print_num(n / base, base);
		return (count + print_num(n % base, base));
	}
}

int	print_format(char format_type, va_list args)
{
	int	count;

	count = 0;
	if(format == 'c')
		count += print_c(va_arg(argvs, int)); // int because you need only 1 byte integer;
	else if (format == 's')
		count += print_s(va_arg(argvs, char *));
	else if (format == 'p')
		count += print_p(va_arg(argvs, char *));
	else if (format == 'd' || format == 'i')
		count += print_num((long)va_arg(argvs, int), 10); // base 10
	//else if (format == 'i')			 // like decimal but does not include decimal (e.g. 1.5, 2.75)
	//	count += print_i(va_arg(argvs, int), 10);
	else if (format == 'u')
		count += print_num((long)va_arg(argvs, unsigned int), 10);
	else if (format == 'x' || format == 'X')
		count += print_num((long)va_arg(argvs, unsigned int), 16);
	//else if (format == 'X')
	//	count += print_num(va_arg(argvs, unsigned int), 16);
	else if (format == '%')
		count += print_percentage(va_arg(argvs, char));
	else
		count += ft_putchar(format_type); // maybe '&' is needed
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int	count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if(*format == '%')
		{
			format++; //advance one time after '%';
			count += print_format(*format, args);
		}
		else
			count += ft_putchar(format);
		format++;
	}
	va_end(args);
	return (count);
}

int	main()
{
	int	count;

	count = ft_printf("%x\n", 42);
	ft_printf("The chars written are %d\n", count);
	count = printf("%x\n", 42);
	printf("The chars written are %d\n", count);

}