/*
** teams.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Tue Oct  7 16:57:12 2014 
** Last Update Thu Oct  9 18:17:48 2014 
*/

#include <stdio.h>
#include <stdlib.h>

#include "graphical_commands.h"

bool		get_graphical_team_description(const s_server* server,
					       const s_args* args, char *buffer)
{
  unsigned int	id;
  bool		correct;

  id = atoi(args->data[1]);
  correct = (id < server->teams.number);

  if (correct)
    snprintf(buffer, BUFFER_SIZE, "TDC %d %s", id, server->teams.names[id]);

  return (correct);
}
