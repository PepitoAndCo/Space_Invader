##
## Makefile for MyLS in /home/remi.verny/UnixSystem/myLS
## 
## Made by Remi Verny
## Login   <remi.verny@epitech.net>
## 
## Started on  Mon Nov 28 15:49:54 2016 Remi Verny
## Last update Sat Apr 15 14:48:26 2017 Extra
##

CC	=	gcc -g

RM	=	rm -f

NAME	=	ex2

CFLAGS	+=	-lncurses -W -Wall -Wextra

SRCS	=	main.c

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
