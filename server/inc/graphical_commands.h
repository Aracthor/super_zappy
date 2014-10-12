/*
** graphical_commands.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Tue Oct  7 16:57:39 2014 
** Last Update Sun Oct 12 00:18:55 2014 
*/

#ifndef GRAPHICAL_COMMANDS_H_
# define GRAPHICAL_COMMANDS_H_

# include "server.h"

/* chunks.c */
bool	get_graphical_chunk(const s_server* server,
			    const s_args* args, char* buffer);

/* teams.c */
bool	get_graphical_team_description(const s_server* server,
				       const s_args* args, char* buffer);

#endif /* !GRAPHICAL_COMMANDS_H_ */
