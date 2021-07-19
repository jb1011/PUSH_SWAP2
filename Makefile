LIB = libft
NAME_CH = checker
NAME_PS = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC_DIR = ./srcs/
INC_DIR = ./include/
OBJ_DIR = ./srcs/
OPTIONS = -I$(INC_DIR) -I./libft -lft -L./libft
HDR = ./includes/push_swap.h

OBJ_PS = srcs/main.o srcs/utils.o srcs/utils2.o
OBJ_PS += srcs/swap_ft.o srcs/chunks.o
OBJ_PS += srcs/sort_b.o srcs/sort_small.o srcs/utils3.o
OBJ_PS += srcs/chunksBig.o srcs/swap_ft2.o srcs/chunks2.o
OBJ_PS += srcs/utils4.o srcs/chunksBig2.o

all: $(LIB) $(NAME_PS)

$(LIB): relib cleanlib

%.o: $(SRC_DIR)%.c $(HDR)
	@$(CC) $(FLAGS) $(OPTIONS) -c $< -o $@

$(NAME_PS): $(OBJ_PS)
	@$(CC) -o $(NAME_PS) $(FLAGS) $(OPTIONS) $(OBJ_PS) libft/libft.a

clean: cleanlib
	@/bin/rm -f $(SRC_DIR)*.o

fclean: clean fcleanlib
	@/bin/rm -f $(NAME_PS)

re: fclean all

relib:
	@$(MAKE) -C ./libft re

cleanlib:
	@$(MAKE) -C ./libft clean

fcleanlib: cleanlib
	@$(MAKE) -C ./libft fclean