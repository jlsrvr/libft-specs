# HEADER

NAME			=	libft.a

CC				=	gcc

OBJS			=	$(SRCS:.c=.o)

SRCS			= 	ft_isdigit.c ft_memcpy.c ft_split.c ft_strmapi.c \
					ft_toupper.c ft_atoi.c ft_isprint.c	\
					ft_memmove.c ft_strchr.c ft_strncmp.c \
					ft_bzero.c ft_itoa.c ft_memset.c ft_strdup.c \
					ft_strnstr.c ft_calloc.c ft_putchar_fd.c \
					ft_strjoin.c ft_strrchr.c ft_isalnum.c \
					ft_memccpy.c ft_putendl_fd.c ft_strlcat.c \
					ft_strtrim.c ft_isalpha.c ft_memchr.c ft_putnbr_fd.c \
					ft_strlcpy.c ft_substr.c ft_isascii.c ft_memcmp.c \
					ft_putstr_fd.c ft_strlen.c ft_tolower.c

BONUS_OBJS		=	$(BONUS_SRCS:.c=.o)

BONUS_SRCS = 		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstnew.c \
					ft_lstsize.c

RM				=	rm -f

FLAGS			=	-Wall -Wextra -Werror

.c.o:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(NAME) $(BONUS_OBJS)
			ar rcs $(NAME) $(BONUS_OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
