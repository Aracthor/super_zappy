##
## Makefile for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
## 
## Made by 
## Login   <aracthor@epitech.net>
## 
## Started on  Sat Oct  4 19:07:52 2014 
## Last Update Sat Oct  4 19:25:56 2014 
##

CC=		gcc

LD=		$(CC)

RM=		rm -f


SRCS_DIR=	srcs/
INC_DIR=	inc/
OBJS_DIR=	objs/
BIN_DIR=	bin/

NAME=		server

SRCS=		$(SRCS_DIR)main.c

OBJS=		$(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)


CFLAGS=		-Wall -Werror -Wextra	\
		-ansi -pedantic		\
		-I $(INC_DIR)		\
		-g3

LDFLAGS=	-o $(BIN_DIR)$(NAME)



$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
		$(CC) $(CFLAGS) -c $< -o $@


$(NAME):	$(OBJS)
		$(LD) $(OBJS) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
