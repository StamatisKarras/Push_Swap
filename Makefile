NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g

LIBFT_A = ./Custom_Libft/libft.a
LIB_DIR = ./Custom_Libft/

SRC = push_swap.c \
	  checks.c \
	  create_stacks.c \
	  free.c \
	  sorting.c \
	  convert.c \
	  instructions.c \
	  small_num.c \
	  instruction_helper.c
OBJ = $(SRC:.c=.o)

.SILENT:

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIB_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT_A) -o $@

re: fclean all

clean:
	rm -rf $(OBJ)
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIB_DIR)

.PHONY: all re clean fclean
