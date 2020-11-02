# HEADER

NAME							=	libft.a

TESTS							= tests

CC								=	gcc

OBJS							=	${SRCS:.c=.o}

OBJS_TESTS				=	${SRCS_TESTS:.c=.o}

SRCS							= $(wildcard ft_*.c)

SRCS_TESTS 				=	${SRCS} \
										test.c

RM								=	rm -f

FLAGS							=	-Wall -Wextra -Werror

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
					ar rcs ${NAME} ${OBJS}

${TESTS}:	${OBJS_TESTS}
					${CC} -o ${TESTS} ${OBJS_TESTS}

all:			${NAME}

clean_t:
					${RM} ${OBJS_TESTS}

fclean_t: clean_t
					${RM} ${TESTS}

clean:
					${RM} ${OBJS}

fclean: 	clean
					${RM} ${NAME}

re: 			fclean all

.PHONY:	all clean fclean re fclean_t clean_t
