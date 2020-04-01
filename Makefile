CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
DEPS=libft/libft.a
HEADERS=libftprintf.h
SRC=ft_printf.c ft_printf_utils.c ft_printf_parsing.c ft_printf_segments.c \
ft_print_utils.c ft_print_char.c ft_print_string.c ft_print_pointer.c \
ft_print_uhexint.c ft_print_percent.c ft_print_integer.c ft_print_uinteger.c
OBJ=$(SRC:.c=.o)
SRC_BONUS=
OBJ_BONUS=$(SRC_BONUS:.c=.o)

ifeq ($(shell ar --version | tr "\n" " " | cut -d ' ' -f 1), GNU)
  CREATELIB=ar rcsT
else
  CREATELIB=libtool -o
endif


all: $(NAME) 

$(NAME): $(DEPS) $(OBJ) $(HEADERS)
	 $(CREATELIB) $(NAME) $(OBJ) $(DEPS)

libft/libft.a:
	make -C libft bonus

bonus: $(DEPS) $(OBJ) $(OBJ_BONUS) $(HEADERS)
	$(CREATELIB) $(LIBTOOLFLAGS) $(NAME) $(OBJ_BONUS) $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean:	clean	
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all
