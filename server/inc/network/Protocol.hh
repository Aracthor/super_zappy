//
// Protocol.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 21 09:14:34 2014 
// Last Update Thu Nov 13 17:09:44 2014 
//

#ifndef PROTOCOL_HH_
# define PROTOCOL_HH_

# include "abstractions/maths.hh"

# define LINE_SEPARATOR	('\n')

# define WELCOME_MESSAGE		"WELCOME\n"
# define AUTHENTIFICATION_IA		"TEAM"
# define AUTHENTIFICATION_GRAPHICAL	"GRAPHIC"
# define KICK_MESSAGE			"GET THE FUCK OUT"

# define GRAPHIC_COMMANDS_NUMBER	(4)
# define GRAPHIC_MAX_ARGS_NUMBER	(10)
# define GRAPHIC_ARGS_SEPARATOR		(" ")

# define IA_COMMANDS_NUMBER		(1)
# define IA_MAX_ARGS_NUMBER		(15)

# define MAX_COMMANDS_NUMBER	(MAX(GRAPHIC_COMMANDS_NUMBER, IA_COMMANDS_NUMBER))
# define MAX_ARGS_NUMBER	(MAX(GRAPHIC_MAX_ARGS_NUMBER, IA_MAX_ARGS_NUMBER))

#endif // !PROTOCOL_HH_
