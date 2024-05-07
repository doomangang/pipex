NAME	= pipex

SRCS 	= pipex.c util.c ./utils/ft_split.c ./utils/ft_strnstr.c ./utils/ft_strjoin.c ./utils/ft_strlen.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= pipex.c

HEADER	= pipex.h

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

all: ${NAME}

%.o: %.c ${INC}/${HEADER}
	${CC} ${CFLAGS} -c $< -o $@ -I${INC}

${NAME}: ${OBJS}
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re