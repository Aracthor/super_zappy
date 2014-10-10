##
## Makefile for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
## 
## Made by 
## Login   <aracthor@epitech.net>
## 
## Started on  Sat Oct  4 19:07:52 2014 
## Last Update Thu Oct  9 18:26:28 2014 
##

CC=		gcc

LD=		$(CC)

RM=		rm -f


SRCS_DIR=	srcs/
INC_DIR=	inc/
OBJS_DIR=	objs/
BIN_DIR=	bin/

ACTION_DIR=		action/
BUFFER_DIR=		buffer/
CLIENT_DIR=		client/
CLIENT_THREAD_DIR=	client_thread/
COMMAND_DIR=		command/
COND_VAR_DIR=		cond_var/
CONFIGS_DIR=		configs/
EXCEPTIONS_DIR=		exceptions/
GRAPHICAL_COMMANDS_DIR=	graphical_commands/
GRAPHICAL_THREAD_DIR=	graphical_thread/
IA_COMMANDS_DIR=	ia_commands/
LIST_DIR=		list/
MAP_DIR=		map/
MUTEX_DIR=		mutex/
MUTEXED_LIST_DIR=	mutexed_list/
NETWORK_DIR=		network/
PLAYER_DIR=		player/
POOL_DIR=		pool/
SERVER_DIR=		server/
SOCKET_DIR=		socket/
TEAMS_DIR=		teams/
THREAD_DIR=		thread/

NAME=		server

SRCS=		$(SRCS_DIR)$(ACTION_DIR)create.c		\
		$(SRCS_DIR)$(BUFFER_DIR)edit.c			\
		$(SRCS_DIR)$(BUFFER_DIR)read.c			\
		$(SRCS_DIR)$(CLIENT_DIR)delete.c		\
		$(SRCS_DIR)$(CLIENT_DIR)init.c			\
		$(SRCS_DIR)$(CLIENT_DIR)interprete.c		\
		$(SRCS_DIR)$(CLIENT_DIR)print.c			\
		$(SRCS_DIR)$(CLIENT_DIR)recognize.c		\
		$(SRCS_DIR)$(CLIENT_DIR)send.c			\
		$(SRCS_DIR)$(CLIENT_DIR)transfer.c		\
		$(SRCS_DIR)$(CLIENT_THREAD_DIR)delete.c		\
		$(SRCS_DIR)$(CLIENT_THREAD_DIR)init.c		\
		$(SRCS_DIR)$(CLIENT_THREAD_DIR)loop.c		\
		$(SRCS_DIR)$(COMMAND_DIR)access.c		\
		$(SRCS_DIR)$(COMMAND_DIR)create.c		\
		$(SRCS_DIR)$(COMMAND_DIR)cut_line_in_args.c	\
		$(SRCS_DIR)$(COND_VAR_DIR)delete.c		\
		$(SRCS_DIR)$(COND_VAR_DIR)signal.c		\
		$(SRCS_DIR)$(COND_VAR_DIR)wait.c		\
		$(SRCS_DIR)$(COND_VAR_DIR)init.c		\
		$(SRCS_DIR)$(CONFIGS_DIR)number_params.c	\
		$(SRCS_DIR)$(CONFIGS_DIR)read_configs.c		\
		$(SRCS_DIR)$(CONFIGS_DIR)string_params.c	\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)allocs.c		\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)cond_var.c		\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)containers.c	\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)handle.c		\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)mutex.c		\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)params.c		\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)syscall.c		\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)thread.c		\
		$(SRCS_DIR)$(GRAPHICAL_COMMANDS_DIR)teams.c	\
		$(SRCS_DIR)$(GRAPHICAL_THREAD_DIR)delete.c	\
		$(SRCS_DIR)$(GRAPHICAL_THREAD_DIR)init.c	\
		$(SRCS_DIR)$(GRAPHICAL_THREAD_DIR)loop.c	\
		$(SRCS_DIR)$(IA_COMMANDS_DIR)test.c		\
		$(SRCS_DIR)$(LIST_DIR)access.c			\
		$(SRCS_DIR)$(LIST_DIR)conditions.c		\
		$(SRCS_DIR)$(LIST_DIR)delete.c			\
		$(SRCS_DIR)$(LIST_DIR)edit.c			\
		$(SRCS_DIR)$(MAP_DIR)delete.c			\
		$(SRCS_DIR)$(MAP_DIR)init.c			\
		$(SRCS_DIR)$(MUTEX_DIR)delete.c			\
		$(SRCS_DIR)$(MUTEX_DIR)lock.c			\
		$(SRCS_DIR)$(MUTEX_DIR)trylock.c		\
		$(SRCS_DIR)$(MUTEX_DIR)unlock.c			\
		$(SRCS_DIR)$(MUTEX_DIR)init.c			\
		$(SRCS_DIR)$(MUTEXED_LIST_DIR)delete.c		\
		$(SRCS_DIR)$(MUTEXED_LIST_DIR)init.c		\
		$(SRCS_DIR)$(NETWORK_DIR)delete.c		\
		$(SRCS_DIR)$(NETWORK_DIR)init.c			\
		$(SRCS_DIR)$(NETWORK_DIR)listen.c		\
		$(SRCS_DIR)$(PLAYER_DIR)delete.c		\
		$(SRCS_DIR)$(PLAYER_DIR)init.c			\
		$(SRCS_DIR)$(POOL_DIR)delete.c			\
		$(SRCS_DIR)$(POOL_DIR)edit.c			\
		$(SRCS_DIR)$(POOL_DIR)init.c			\
		$(SRCS_DIR)$(SERVER_DIR)delete.c		\
		$(SRCS_DIR)$(SERVER_DIR)init.c			\
		$(SRCS_DIR)$(SERVER_DIR)see_what_happened.c	\
		$(SRCS_DIR)$(SERVER_DIR)start.c			\
		$(SRCS_DIR)$(SOCKET_DIR)delete.c		\
		$(SRCS_DIR)$(SOCKET_DIR)init.c			\
		$(SRCS_DIR)$(TEAMS_DIR)access.c			\
		$(SRCS_DIR)$(THREAD_DIR)delete.c		\
		$(SRCS_DIR)$(THREAD_DIR)init.c			\
		$(SRCS_DIR)$(THREAD_DIR)join.c			\
		$(SRCS_DIR)main.c				\
		$(SRCS_DIR)output.c

OBJS=		$(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

BINARY=		$(BIN_DIR)$(NAME)


CFLAGS=		-Wall -Werror -Wextra	\
		-ansi -pedantic		\
		-D_BSD_SOURCE		\
		-I $(INC_DIR)		\
		-g3

LDFLAGS=	-o $(BINARY)	\
		-lpthread



$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
		$(CC) $(CFLAGS) -c $< -o $@


$(BINARY):	$(OBJS)
		$(LD) $(OBJS) $(LDFLAGS)

all:		$(BINARY)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
