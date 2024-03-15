
NAME = libftprintf.a

SRC = ft_printf.c ft_putchar.c print_type_d_i.c print_type_p.c\
print_type_s.c print_type_u.c print_type_x.c

HEAD = includes

OBJ = ${SRC:.c=.o}

CC = gcc

CFLAG = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

all: ${NAME}

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