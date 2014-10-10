/*
** init.c<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Thu Oct  9 18:22:28 2014 
** Last Update Thu Oct  9 18:27:37 2014 
*/

#include "exception.h"
#include "map.h"

void	map_init(s_map* map, const s_map_configs* configs)
{
  map->longer = configs->longer;
  map->larger = configs->larger;
  MALLOC(map->hooplas, sizeof(s_hoopla) * configs->longer * configs->larger);
}
