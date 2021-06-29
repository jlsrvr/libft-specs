NAME			=	test


ifeq ($(shell uname),Darwin)
	CC		=	gcc
	SYSTEM	=	macos
	LIBS	=	-L./srcs -lft
else
	CC		=	clang
	SYSTEM	=	linux
	LIBS	=	-L./srcs -lft -lbsd
endif

IDIR			=	srcs/headers/

OBJS_TEST		=	$(SRC_TEST:.c=.o)

SRCS_TEST		=	$(addprefix specs/, $(SRC_TEST))

SRC_TEST 		=	$(wildcard specs/*.c)

RM				=	rm -f

FLAGS			=	-Wall -Wextra -D SYSTEM=$(SYSTEM) $(ARGS)

.c.o:
	$(CC) $(FLAGS) -I$(IDIR) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	make_lib $(OBJS_TEST)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS_TEST) $(LIBS)

make_lib:
	@make libft.a -C ./srcs

clean:
	$(RM) $(OBJS_TEST)
	@make clean -C ./srcs

fclean: 	clean
	$(RM) $(NAME)
	@make fclean -C ./srcs

re:			fclean all

.PHONY:	all clean fclean re
