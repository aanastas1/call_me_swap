NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/push_swap.c src/parsing/parse_args.c src/bench.c
# Add the rest of your .c files here, for example:
# SRC = push_swap.c utils.c parse.c strategies_simple.c strategies_medium.c strategies_complex.c strategies_adaptive.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Isrc -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
