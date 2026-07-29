NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -I.
LDFLAGS = -Llibft -lft

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = \
	push_swap.c \
	parse_args.c \
	parse_args_assistants.c \
	prepare_stacks.c \
	assistant_functions.c \
	op_swap.c \
	op_push.c \
	op_rotate.c \
	op_reverse_rotate.c \
	utils_sorting.c \
	sort_small.c \
	bench.c \
	bench_output.c \
	strategy_simple.c \
	strategy_medium.c \
	strategy_complex.c

HDRS = push_swap.h libft/libft.h

BONUS_SRCS = \
	checker_bonus.c \
	checker_parse_args_bonus.c \
	assistant_functions_bonus.c \
	util_functions_bonus.c \
	prepare_stacks_bonus.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \
	op_swap_bonus.c \
	op_push_bonus.c \
	op_rotate_bonus.c \
	op_reverse_rotate_bonus.c

BONUS_HDRS = checker_bonus.h libft/libft.h

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(SRCS) $(HDRS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(SRCS) $(LDFLAGS)

$(BONUS_NAME): $(BONUS_SRCS) $(BONUS_HDRS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(BONUS_SRCS) $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f *.o

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all bonus

.PHONY: all bonus clean fclean re
