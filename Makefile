NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
RM = rm -f
AR = ar
CRS = crs
INC_DIR = includes
SRCS_DIR = srcs

SRCS = $(addprefix $(SRCS_DIR)/, main.c ft_atoi.c op_swap.c op_rotation.c op_reverse_rotation.c op_push.c sort_over_5.c sort_under_5.c utils.c error.c ft_split.c check_split.c init.c sort_under_5_utils.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -I $(INC_DIR) $< -o $@

$(NAME): $(OBJS)
		$(CC) -o $@ $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: fclean all clean re