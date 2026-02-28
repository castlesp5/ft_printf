NAME = libftprintf.a
SRCS = ft_printf.c\
			 funcs/func.c\
			 funcs/unsigned.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	gcc $(NAME) -Wall -Wextra -Werror

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
