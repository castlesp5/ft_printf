NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I. -g
SRCS = ft_printf.c\
			 funcs/func.c\
			 funcs/unsigned.c\
			 funcs/bonus.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: all
	cc main.c $(CFLAGS) -L. -lftprintf -Llibft -lft -o test

.PHONY: all clean fclean re
