CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRC =  ft_libft.c ft_libft2.c\
	ft_printf.c parsing.c ft_printf2.c\
	ft_putc.c 	ft_putdi.c \
	ft_putp.c ft_puts.c ft_putu.c ft_putx.c ft_putxx.c ft_putx2.c ft_putxx2.c

OBJS = $(SRC:.c=.o)

# $(NAME): $(OBJS)
# 	cc -o $(NAME) $(OBJS)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f  $(NAME) $(BONUS_OBJS)

re: fclean all

# bonus: all

.PHONY: all clean fclean re bonus
