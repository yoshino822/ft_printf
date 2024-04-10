cmake_minimum_required(VERSION 3.26)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)

add_executable(ft_printf ft_printf.c ft_putchar.c print_type_d_i.c print_type_p.c print_type_s.c print_type_u.c print_type_x.c)
