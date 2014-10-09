/*
** access.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Tue Oct  7 10:17:33 2014 
** Last Update Tue Oct  7 16:59:45 2014 
*/

#include <string.h>

#include "teams.h"

int	get_team_id(const s_teams* teams, char* team)
{
  int	id;

  id = 0;
  while (id < (int)teams->number &&
	 strcmp(teams->names[id], team))
    ++id;

  if (id == (int)teams->number)
    id = -1;

  return (id);
}
