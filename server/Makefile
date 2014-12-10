##
## Makefile for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
## 
## Made by 
## Login   <aracthor@epitech.net>
## 
## Started on  Sat Oct  4 19:07:52 2014 
## Last Update Wed Dec 10 13:36:04 2014 
##

CC=		g++

LD=		$(CC)

RM=		rm -f


SRCS_DIR=	srcs/
INC_DIR=	inc/
OBJS_DIR=	objs/
BIN_DIR=	bin/

ABSTRACTION_DIR=abstractions/
ACTIONS_DIR=	actions/
CATALOGS_DIR=	catalogs/
CORE_DIR=	core/
DATA_DIR=	data/
DEBUG_DIR=	debug/
EXCEPTIONS_DIR=	exceptions/
EXECUTORS_DIR=	executors/
INIT_DIR=	init/
MAP_DIR=	map/
NCURSES_DIR=	ncursesxx/
NETWORK_DIR=	network/
SECURITY_DIR=	security/
THREADING_DIR=	threading/

CONSOLES_DIR=	$(CORE_DIR)consoles/
DISPLACERS_DIR=	$(EXECUTORS_DIR)displacers/
GENERATORS_DIR=	$(MAP_DIR)generators/
LISTENERS_DIR=	$(NETWORK_DIR)listeners/
TIMECALCS_DIR=	$(ACTIONS_DIR)timecalcs/

NAME=		server

SRCS=		$(SRCS_DIR)$(ABSTRACTION_DIR)Clock.cpp			\
		$(SRCS_DIR)$(ABSTRACTION_DIR)Pipe.cpp			\
		$(SRCS_DIR)$(ABSTRACTION_DIR)SigsegvHandler.cpp		\
		$(SRCS_DIR)$(ACTIONS_DIR)Action.cpp			\
		$(SRCS_DIR)$(ACTIONS_DIR)ActionFactory.cpp		\
		$(SRCS_DIR)$(ACTIONS_DIR)ActionsManager.cpp		\
		$(SRCS_DIR)$(ACTIONS_DIR)ExecuterThread.cpp		\
		$(SRCS_DIR)$(CATALOGS_DIR)Craft.cpp			\
		$(SRCS_DIR)$(CATALOGS_DIR)CraftCatalog.cpp		\
		$(SRCS_DIR)$(CATALOGS_DIR)Ground.cpp			\
		$(SRCS_DIR)$(CATALOGS_DIR)GroundCatalog.cpp		\
		$(SRCS_DIR)$(CATALOGS_DIR)Object.cpp			\
		$(SRCS_DIR)$(CATALOGS_DIR)ObjectCatalog.cpp		\
		$(SRCS_DIR)$(CATALOGS_DIR)Production.cpp		\
		$(SRCS_DIR)$(CATALOGS_DIR)ReadableFromZCSV.cpp		\
		$(SRCS_DIR)$(CATALOGS_DIR)WeaponPlan.cpp		\
		$(SRCS_DIR)$(CATALOGS_DIR)WeaponCatalog.cpp		\
		$(SRCS_DIR)$(CONSOLES_DIR)ClientsConsole.cpp		\
		$(SRCS_DIR)$(CONSOLES_DIR)ColorFactory.cpp		\
		$(SRCS_DIR)$(CONSOLES_DIR)Console.cpp			\
		$(SRCS_DIR)$(CONSOLES_DIR)LogConsole.cpp		\
		$(SRCS_DIR)$(CONSOLES_DIR)LogsConsole.cpp		\
		$(SRCS_DIR)$(CONSOLES_DIR)PlayersConsole.cpp		\
		$(SRCS_DIR)$(CONSOLES_DIR)PromptConsole.cpp		\
		$(SRCS_DIR)$(CORE_DIR)AExecuter.cpp			\
		$(SRCS_DIR)$(CORE_DIR)CommandExecuter.cpp		\
		$(SRCS_DIR)$(CORE_DIR)ControlPanel.cpp			\
		$(SRCS_DIR)$(CORE_DIR)LinkedToServer.cpp		\
		$(SRCS_DIR)$(CORE_DIR)LogThread.cpp			\
		$(SRCS_DIR)$(CORE_DIR)Server.cpp			\
		$(SRCS_DIR)$(CORE_DIR)SingletonManager.cpp		\
		$(SRCS_DIR)$(DATA_DIR)Class.cpp				\
		$(SRCS_DIR)$(DATA_DIR)Equipement.cpp			\
		$(SRCS_DIR)$(DATA_DIR)GameData.cpp			\
		$(SRCS_DIR)$(DATA_DIR)Hurtable.cpp			\
		$(SRCS_DIR)$(DATA_DIR)Inventory.cpp			\
		$(SRCS_DIR)$(DATA_DIR)Namable.cpp			\
		$(SRCS_DIR)$(DATA_DIR)Player.cpp			\
		$(SRCS_DIR)$(DATA_DIR)Team.cpp				\
		$(SRCS_DIR)$(DATA_DIR)Weapon.cpp			\
		$(SRCS_DIR)$(DEBUG_DIR)ConsoleLog.cpp			\
		$(SRCS_DIR)$(DEBUG_DIR)Log.cpp				\
		$(SRCS_DIR)$(DEBUG_DIR)LogManager.cpp			\
		$(SRCS_DIR)$(DEBUG_DIR)LogParameter.cpp			\
		$(SRCS_DIR)$(DEBUG_DIR)StandartLog.cpp			\
		$(SRCS_DIR)$(DEBUG_DIR)outputs.cpp			\
		$(SRCS_DIR)$(DEBUG_DIR)usefull.cpp			\
		$(SRCS_DIR)$(DISPLACERS_DIR)AdeptDisplacer.cpp		\
		$(SRCS_DIR)$(DISPLACERS_DIR)ApprenticeDisplacer.cpp	\
		$(SRCS_DIR)$(DISPLACERS_DIR)DisplacerMethod.cpp		\
		$(SRCS_DIR)$(DISPLACERS_DIR)ExpertDisplacer.cpp		\
		$(SRCS_DIR)$(DISPLACERS_DIR)MasterDisplacer.cpp		\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)ConfigsException.cpp	\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)FileException.cpp		\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)NetworkException.cpp	\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)SignalException.cpp		\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)StartException.cpp		\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)SyscallException.cpp	\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)ThreadingException.cpp	\
		$(SRCS_DIR)$(EXCEPTIONS_DIR)ZappyException.cpp		\
		$(SRCS_DIR)$(EXECUTORS_DIR)Attacker.cpp			\
		$(SRCS_DIR)$(EXECUTORS_DIR)Crafter.cpp			\
		$(SRCS_DIR)$(EXECUTORS_DIR)Destroyer.cpp		\
		$(SRCS_DIR)$(EXECUTORS_DIR)Digger.cpp			\
		$(SRCS_DIR)$(EXECUTORS_DIR)Displacer.cpp		\
		$(SRCS_DIR)$(EXECUTORS_DIR)Equipper.cpp			\
		$(SRCS_DIR)$(EXECUTORS_DIR)Mailer.cpp			\
		$(SRCS_DIR)$(EXECUTORS_DIR)Mover.cpp			\
		$(SRCS_DIR)$(EXECUTORS_DIR)Movements.cpp		\
		$(SRCS_DIR)$(EXECUTORS_DIR)PlayerLocater.cpp		\
		$(SRCS_DIR)$(EXECUTORS_DIR)Putter.cpp			\
		$(SRCS_DIR)$(EXECUTORS_DIR)Rotater.cpp			\
		$(SRCS_DIR)$(EXECUTORS_DIR)Searcher.cpp			\
		$(SRCS_DIR)$(EXECUTORS_DIR)SpeedCalculator.cpp		\
		$(SRCS_DIR)$(EXECUTORS_DIR)Taker.cpp			\
		$(SRCS_DIR)$(GENERATORS_DIR)AGenerator.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)ATerraformer.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)GroundGenerator.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)HeightGenerator.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)HeightMap.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)LowLakeGenerator.cpp	\
		$(SRCS_DIR)$(GENERATORS_DIR)MoistureCalculator.cpp	\
		$(SRCS_DIR)$(GENERATORS_DIR)MountainMap.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)ObjectGenerator.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)PerlinMap.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)RandomMap.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)RingMap.cpp			\
		$(SRCS_DIR)$(GENERATORS_DIR)RiverGenerator.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)Terraformer.cpp		\
		$(SRCS_DIR)$(GENERATORS_DIR)WaterGenerator.cpp		\
		$(SRCS_DIR)$(INIT_DIR)Configs.cpp			\
		$(SRCS_DIR)$(INIT_DIR)Teams.cpp				\
		$(SRCS_DIR)$(LISTENERS_DIR)AuthentificationListener.cpp	\
		$(SRCS_DIR)$(LISTENERS_DIR)CommandCutter.cpp		\
		$(SRCS_DIR)$(LISTENERS_DIR)CommandListener.cpp		\
		$(SRCS_DIR)$(LISTENERS_DIR)GraphicListener.cpp		\
		$(SRCS_DIR)$(LISTENERS_DIR)TeamListener.cpp		\
		$(SRCS_DIR)$(MAP_DIR)Chunk.cpp				\
		$(SRCS_DIR)$(MAP_DIR)Hoopla.cpp				\
		$(SRCS_DIR)$(MAP_DIR)Map.cpp				\
		$(SRCS_DIR)$(MAP_DIR)NamesRegister.cpp			\
		$(SRCS_DIR)$(NCURSES_DIR)Application.cpp		\
		$(SRCS_DIR)$(NCURSES_DIR)Color.cpp			\
		$(SRCS_DIR)$(NCURSES_DIR)NcursesException.cpp		\
		$(SRCS_DIR)$(NCURSES_DIR)Window.cpp			\
		$(SRCS_DIR)$(NETWORK_DIR)Client.cpp			\
		$(SRCS_DIR)$(NETWORK_DIR)ListenThread.cpp		\
		$(SRCS_DIR)$(NETWORK_DIR)Network.cpp			\
		$(SRCS_DIR)$(NETWORK_DIR)Socket.cpp			\
		$(SRCS_DIR)$(NETWORK_DIR)SpeakThread.cpp		\
		$(SRCS_DIR)$(SECURITY_DIR)CheatChecker.cpp		\
		$(SRCS_DIR)$(SECURITY_DIR)SkillChecker.cpp		\
		$(SRCS_DIR)$(SECURITY_DIR)StatChecker.cpp		\
		$(SRCS_DIR)$(THREADING_DIR)AZappyThread.cpp		\
		$(SRCS_DIR)$(THREADING_DIR)AThread.cpp			\
		$(SRCS_DIR)$(THREADING_DIR)CondVar.cpp			\
		$(SRCS_DIR)$(THREADING_DIR)Mutex.cpp			\
		$(SRCS_DIR)$(THREADING_DIR)ThreadManager.cpp		\
		$(SRCS_DIR)$(TIMECALCS_DIR)CraftTimeCalculator.cpp	\
		$(SRCS_DIR)$(TIMECALCS_DIR)DestroyerTimeCalculator.cpp	\
		$(SRCS_DIR)$(TIMECALCS_DIR)DiggerTimeCalculator.cpp	\
		$(SRCS_DIR)main.cpp					\

OBJS=		$(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)

BINARY=		$(BIN_DIR)$(NAME)


CXXFLAGS=	-Wall -Werror -Wextra	\
		-ansi -pedantic		\
		-D_BSD_SOURCE		\
		-D_BUFFER_STACK_MODE	\
		-I $(INC_DIR)		\
		-g3

LIBS=		pthread	\
		ncurses

LDFLAGS=	-o $(BINARY)	\
		$(LIBS:%=-l%)



$(BINARY):	$(OBJS)
		$(LD) $(OBJS) $(LDFLAGS)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.cpp
		$(CC) $(CXXFLAGS) -c $< -o $@

all:		$(BINARY)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(BINARY)

re:		fclean all
