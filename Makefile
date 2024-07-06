CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = a.out
SRC =  ft_atoi.c ft_printf.c parsing.c ft_printf2.c

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	cc $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f  $(NAME) $(BONUS_OBJS)

re: fclean all

.PHONY: all clean fclean re bonus
