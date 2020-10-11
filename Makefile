##
## ETNA PROJECT, 11/12/2018 by [...]
## [...]
## File description:
##      [...]
##

CC	=	gcc

RM	=	rm -f

CFLAGS  =   -Wall -Wextra -Werror $(shell sdl2-config --cflags --libs)

NAME	=	Jetpack

SRCS	=	checker.c   \
			base.c      \
			error.c     \
			main.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
