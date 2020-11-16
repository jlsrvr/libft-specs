# HEADER

NAME							=	libft.a

TESTS							= tests

CC								=	gcc

OBJS							=	${SRCS:.c=.o}

OBJS_TEST					=	${SRCS_TEST:.c=.o}

SRCS							= $(wildcard ft_*.c)

SRCS_TEST 				=	$(wildcard specs/*.c)	\
										specs_runner.c

RM								=	rm -f

FLAGS							=	-Wall -Wextra -Werror

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
					ar rcs ${NAME} ${OBJS}

${TEST}: 	${NAME} ${OBJS_TEST}
					${CC} -o ${TEST} ${OBJS_TEST} -L. -lft

all:			${NAME}

clean_t:
					${RM} ${OBJS_TEST} ${OBJS}

fclean_t: clean_t
					${RM} ${TEST} ${NAME}

clean:
					${RM} ${OBJS}

fclean: 	clean
					${RM} ${NAME}

re: 			fclean all

.PHONY:	all clean fclean re fclean_t clean_t
