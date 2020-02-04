CC=gcc
CFLAGS=-Wall -Wextra -Werror
ARFLAGS=rcs
NAME=libftprintf.a
DEPS=libft/libft.a
HEADERS=libftprintf.h
SRC=ft_printf.c print_int.c print_uint.c
OBJ=$(SRC:.c=.o)
SRC_BONUS=
OBJ_BONUS=$(SRC_BONUS:.c=.o)

all: $(NAME) 

$(NAME): $(DEPS) $(OBJ) $(HEADERS)
	ar $(ARFLAGS) $(NAME) $(OBJ)

libft/libft.a:
	cd libft && make

bonus: $(DEPS) $(OBJ) $(OBJ_BONUS) $(HEADERS)
	ar $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o
	cd libft && make clean

fclean:	clean	
	rm -rf $(NAME)
	cd libft && make fclean

re: fclean all
