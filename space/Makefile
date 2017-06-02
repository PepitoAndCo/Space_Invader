##
## Makefile for MyLS in /home/remi.verny/UnixSystem/myLS
## 
## Made by Remi Verny
## Login   <remi.verny@epitech.net>
## 
## Started on  Mon Nov 28 15:49:54 2016 Remi Verny
## Last update Sat Apr 15 16:49:12 2017 Remi Verny
##

CC	=	gcc -g

RM	=	rm -f

NAME	=	space

CFLAGS	+=	-I./include -lncurses -W -Wall -Wextra

SRCS	=	main.c		\
		get_next_line.c	\
		tools.c		\
		get_vars.c	\
		random.c	\
		moving.c	\
		tab_create.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
