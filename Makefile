# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybollen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 13:27:11 by ybollen           #+#    #+#              #
#    Updated: 2024/03/20 13:27:13 by ybollen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_putchar.c print_type_d_i.c print_type_p.c\
print_type_s.c print_type_u.c print_type_x.c


OBJ = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}



${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}
	@echo "${NAME} created"

clean:
	rm -f ${OBJ}
	@echo "${OBJ} deleted"

fclean: clean
	rm -f ${NAME}
	@echo "${NAME} deleted"

re: fclean all
	@echo "${NAME} ${OBJ} returned"

.PHONY: all clean fclean re
