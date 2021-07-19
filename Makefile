NAME = push_swap
SRC = srcs/main.c srcs/utils.c srcs/utils2.c \
srcs/swap_ft.c srcs/chunks.c \
srcs/sort_b.c srcs/sort_small.c srcs/utils3.c \
srcs/chunksBig.c srcs/swap_ft2.c srcs/chunks2.c \
srcs/utils4.c srcs/chunksBig2.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
CC = gcc
	
.PHONY: clean fclean re re-bis
	
all : $(NAME)
	
$(NAME):
	@make -C libft/
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I libft/ -L libft/ -lft
	
clean:
	@make -C libft/ clean
	@rm -f $(OBJ)
	
fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	
re: fclean all
	
re-bis:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I libft/ -L libft/ -lft