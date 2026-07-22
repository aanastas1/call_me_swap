NAME = push_swap

SRC_DIR = src
INC_DIR = include

SRCS	=	$(SRC_DIR)/main.c \
$(SRC_DIR)/push_swap.c \
$(SRC_DIR)/parse_args.c \
$(SRC_DIR)/op_swap.c \
$(SRC_DIR)/op_push.c \
$(SRC_DIR)/op_rotate.c \
$(SRC_DIR)/op_reverse_rotate.c \
$(SRC_DIR)/complex_string_split.c \
$(SRC_DIR)/assistant_functions.c \
$(SRC_DIR)/sort_stacks.c \
$(SRC_DIR)/prepare_stacks.c \
$(SRC_DIR)/strategy_medium.c \
$(SRC_DIR)/utils_sorting.c \
$(SRC_DIR)/sort_small.c \
$(SRC_DIR)/bench.c \
$(SRC_DIR)/bench_output.c \
$(SRC_DIR)/strategy_simple.c 

# Add the rest of your .c files here, for example:
# SRC = push_swap.c utils.c parse.c strategies_simple.c strategies_medium.c strategies_complex.c strategies_adaptive.c

HDRS = $(INC_DIR)/push_swap.h \
	libft/libft.h 	

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -fsanitize=address -g

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

LDFLAGS = -L$(LIBFT_PATH) -lft -L.

all: $(NAME)

$(NAME): $(SRCS) $(HDRS) $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT) 

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
