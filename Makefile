NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibft -lft

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

HDRS = push_swap.h libft/libft.hclear
BONUS_HDRS = checker_bonus.h libft/libft.h

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
	assistants_sorting.c \
	sort_small.c \
	bench.c \
	bench_output.c \
	strategy_simple.c \
	strategy_medium.c \
	strategy_complex.c

BONUS_SRCS = \
	checker_bonus.c \
	checker_parse_args_bonus.c \
	parse_assistant_functions_bonus.c \
	assistant_functions_bonus.c \
	prepare_stacks_bonus.c \
	stdinput_reading_bonus.c \
	op_swap_bonus.c \
	op_push_bonus.c \
	op_rotate_bonus.c \
	op_reverse_rotate_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LDFLAGS)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

bonus%.o: %.c $(BONUS_HDRS)
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all 

.PHONY: all bonus clean fclean re
