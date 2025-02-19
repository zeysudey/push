NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf

LIBFT = libft/libft.a

SRC = list.c arg_counts.c push_swap.c sort.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
		make -C ./libft

clean:
		make clean -C ./libft
		$(RM) $(OBJ)

fclean: clean
		make fclean -C ./libft
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re