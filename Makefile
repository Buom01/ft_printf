CC=gcc
CFLAGS=-Wall -Wextra -Werror
ARFLAGS=rcs
NAME=libftprintf.a
DEPS=
HEADERS=libftprintf.h
SRC=ft_printf.c putchar.c print_int.c print_uint.c
OBJ=$(SRC:.c=.o)
SRC_BONUS=
OBJ_BONUS=$(SRC_BONUS:.c=.o)

all: $(NAME) 

$(NAME): $(DEPS) $(OBJ) $(HEADERS)
	ar $(ARFLAGS) $(NAME) $(OBJ)

bonus: $(DEPS) $(OBJ) $(OBJ_BONUS) $(HEADERS)
	ar $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean:	clean	
		rm -rf $(NAME)

re: fclean all
