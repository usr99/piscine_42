NAME		= libft.a

SRCS_DIR	= srcs/

SRCS		= ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c

OBJS		= $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

HEADERS		= includes

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

.c.o:
		${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		ar rc ${NAME} ${OBJS}

all: 	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: 	fclean all

.PHONY: all clean fclean re
