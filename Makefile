NAME = push_swap

MAIN = ./main.c

OBJ_MAIN = ${MAIN:.c=.o}

SRCS = srcs/utils.c srcs/utils2.c srcs/swap_ft.c \
srcs/chunks.c srcs/sort_b.c srcs/sort_small.c srcs/utils3.c \
srcs/chunksBig.c srcs/swap_ft2.c srcs/chunks2.c srcs/utils4.c

PATH_SRCS = ./

_SRCS = ${addprefix ${PATH_SRCS}, ${SRCS}}

OBJS = ${_SRCS:.c=.o}

LINK = ar rc

CC = gcc

FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

RM = rm -rf

PATH_HEADER = ./

.c.o:
			${CC} ${FLAGS} -I${PATH_HEADER} -c $< -o ${<:.c=.o}

MYLIB = mylib.a

LIBFTLIB = ./libft/

all:        ${NAME}

${NAME}:    ${MV} ${OBJ_MAIN} ${OBJS}
			${LINK} ${MYLIB} ${OBJS}
			ranlib ${MYLIB}
			${CC} ${FLAGS} -o3 ${OBJ_MAIN} ${MYLIB} -o ${NAME} libft.a

clean:
			${RM} ${OBJ_MAIN} ${OBJS}

fclean:     clean
			${RM} ${NAME} ${MYLIB}

re:         fclean all

.PHONY:     all clean fclean re