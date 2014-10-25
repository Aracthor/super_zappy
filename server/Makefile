##
## Makefile for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
## 
## Made by 
## Login   <aracthor@epitech.net>
## 
## Started on  Sat Oct  4 19:07:52 2014 
## Last Update Fri Oct 24 17:21:11 2014 
##

CC=		g++

LD=		$(CC)

RM=		rm -f


SRCS_DIR=	srcs/
INC_DIR=	inc/
OBJS_DIR=	objs/
BIN_DIR=	bin/

ABSTRACT_DIR=	abstractions/
CORE_DIR=	core/
DEBUG_DIR=	debug/
EXCEPTIONS_DIR=	exceptions/
INIT_DIR=	init/
MAP_DIR=	map/
NETWORK_DIR=	network/
THREADING_DIR=	threading/

GENERATORS_DIR=	$(MAP_DIR)generators/
LISTENERS_DIR=	$(NETWORK_DIR)listeners/

NAME=		server

SRCS=		$(SRCS_DIR)$(ABSTRACT_DIR)Random.cpp			\
		$(SRCS_DIR)$(CORE_DIR)GameData.cpp			\
		$(SRCS_DIR)$(CORE_DIR)Server.cpp			\
		$(SRCS_DIR)$(CORE_DIR)SingletonManager.cpp		\
		$(SRCS_DIR)$(DEBUG_DIR)Log.cpp				\
		$(SRCS_DIR)$(DEBUG_DIR)LogManager.cpp			\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)ConfigsException.cpp	\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)NetworkException.cpp	\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)SyscallException.cpp	\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)ThreadingException.cpp	\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)ZappyException.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)ATerraformer.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)GroundGenerator.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)HeightMap.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)MountainMap.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)PerlinMap.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)RandomMap.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)Terraformer.cpp		\
		$(SRCS_DIR)$(INIT_DIR)Configs.cpp			\
		$(SRCS_DIR)$(INIT_DIR)Teams.cpp				\
		$(SRCS_DIR)$(LISTENERS_DIR)AuthentificationListener.cpp	\
		$(SRCS_DIR)$(LISTENERS_DIR)CommandCutter.cpp		\
		$(SRCS_DIR)$(LISTENERS_DIR)GraphicListener.cpp		\
		$(SRCS_DIR)$(LISTENERS_DIR)GraphicMessages.cpp		\
		$(SRCS_DIR)$(LISTENERS_DIR)IAListener.cpp		\
		$(SRCS_DIR)$(MAP_DIR)Chunk.cpp				\
		$(SRCS_DIR)$(MAP_DIR)Hoopla.cpp				\
		$(SRCS_DIR)$(MAP_DIR)Map.cpp				\
		$(SRCS_DIR)$(NETWORK_DIR)Client.cpp			\
		$(SRCS_DIR)$(NETWORK_DIR)ListenThread.cpp		\
		$(SRCS_DIR)$(NETWORK_DIR)Network.cpp			\
		$(SRCS_DIR)$(NETWORK_DIR)Socket.cpp			\
		$(SRCS_DIR)$(NETWORK_DIR)SpeakThread.cpp		\
		$(SRCS_DIR)$(THREADING_DIR)AZappyThread.cpp		\
		$(SRCS_DIR)$(THREADING_DIR)AThread.cpp			\
		$(SRCS_DIR)$(THREADING_DIR)CondVar.cpp			\
		$(SRCS_DIR)$(THREADING_DIR)Mutex.cpp			\
		$(SRCS_DIR)$(THREADING_DIR)ThreadManager.cpp		\
		$(SRCS_DIR)main.cpp					\

OBJS=		$(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)

BINARY=		$(BIN_DIR)$(NAME)


CXXFLAGS=	-Wall -Werror -Wextra	\
		-ansi -pedantic		\
		-D_BSD_SOURCE		\
		-I $(INC_DIR)		\
		-g3

LDFLAGS=	-o $(BINARY)	\
		-lpthread



$(BINARY):	$(OBJS)
		$(LD) $(OBJS) $(LDFLAGS)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.cpp
		$(CC) $(CXXFLAGS) -c $< -o $@

all:		$(BINARY)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
