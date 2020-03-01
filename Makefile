CC=gcc
CFLAGS=-Wall -Wextra -Werror
ARFLAGS=rcsT
NAME=libftprintf.a
DEPS=libft/libft.a
HEADERS=libftprintf.h
SRC=ft_printf.c ft_printf_utils.c ft_printf_parsing.c ft_print_char.c \
ft_print_string.c
OBJ=$(SRC:.c=.o)
SRC_BONUS=
OBJ_BONUS=$(SRC_BONUS:.c=.o)

all: $(NAME) 

$(NAME): $(DEPS) $(OBJ) $(HEADERS)
	ar $(ARFLAGS) $(NAME) $(OBJ) ${DEPS}

libft/libft.a:
	make -C libft bonus

bonus: $(DEPS) $(OBJ) $(OBJ_BONUS) $(HEADERS)
	ar $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_BONUS) ${DEPS}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:	clean	
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all
