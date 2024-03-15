


#include "ft_printf.h"

void	print_format(char format_type, va_list args, int *len)
{
	if(format_type == 'c')
		len += ft_putchar(va_arg(args, int)); // int because you need only 1 byte integer; //maybe wrong
	else if (format_type == 's')
		len += print_type_s(va_arg(args, char *));
	else if (format_type == 'p')
		print_type_p((unsigned long int)va_arg(args, void *), len);
	else if (format_type == 'd' || format_type == 'i')
		print_type_d_i(va_arg(args, int), len); // base 10
	else if (format_type == 'u')
		print_type_u(va_arg(args, unsigned int), len);
	else if (format_type == 'x')
		print_type_x(va_arg(args, unsigned int), len, 'x');
	else if (format_type == 'X')
		print_type_x(va_arg(args, unsigned int), len, 'X');
	else if (format_type == '%')
		len += ft_putchar('%'); //maybe wrong
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int	len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if(*format == '%')
		{
			format++; //advance one time after '%';
			print_format(*format, args, &len);
		}
		else
			len++;
			ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	int	count;

	count = ft_printf("%x\n", 42);
	ft_printf("The chars written are %d\n", count);
	count = printf("%x\n", 42);
	printf("The chars written are %d\n", count);
	return (0);
}*/