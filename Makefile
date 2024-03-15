
NAME = libftprintf.a

SRC = ft_printf.c print_format.c print_num.c print_s.c print_c.c

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