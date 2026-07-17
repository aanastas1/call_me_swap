NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

SRC = tests/main.c \
	src/push_swap.c \
	src/parsing/parse_args.c \
	src/parsing/bench.c \
	src/check_stack.c \
	src/prepare_stacks.c \
	src/sorting/sort_small.c \
	src/sorting/turk_alg.c \
	src/operations/op_swap_n_push.c \
	src/operations/op_rotate.c \
	src/operations/op_reverse_rotate.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re test-small

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c
	$(CC) $(CFLAGS) -Isrc -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) test_small_sort

re: fclean all

test-small:
	$(CC) $(CFLAGS) -Isrc tests/test_small_sort.c src/sorting/sort_small.c \
		src/operations/op_swap_n_push.c src/operations/op_rotate.c \
		src/operations/op_reverse_rotate.c src/check_stack.c \
		$(LIBFT) -o test_small_sort
	./test_small_sort >/dev/null
	rm -f test_small_sort
