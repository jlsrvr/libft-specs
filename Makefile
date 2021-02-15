NAME			=	test

CC				=	gcc

OBJS_TEST		=	$(SRC_TEST:.c=.o)

SRCS_TEST		=	$(addprefix specs/, $(SRC_TEST))

SRC_TEST 		=	$(wildcard specs/*.c)

RM				=	rm -f

FLAGS			=	-Wall -Wextra $(ARGS)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS_TEST) $(LIB)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS_TEST) -L ./srcs -lft

all:		$(NAME)

LIB:
	$(MAKE) -C srcs

clean:
	$(RM) $(OBJS_TEST)

fclean: 	clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
