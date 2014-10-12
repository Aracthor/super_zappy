/*
** delete.c<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Thu Oct  9 18:24:26 2014 
** Last Update Sun Oct 12 00:17:41 2014 
*/

#include "exception.h"
#include "map.h"

void	map_delete(s_map* map)
{
  FREE(map->chunks);
}
