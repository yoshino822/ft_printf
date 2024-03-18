

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_putchar(char c);
void	print_type_p(size_t n, int *len);
void	print_type_d_i(int n, int *len);
void	print_type_u(unsigned int n, int *len);
void	print_type_x(unsigned int n, int *len, int hexa);

int ft_printf(const char *format, ...);
int	print_type_s(char *str);

#endif
