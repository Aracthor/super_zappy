/*
** init.c<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Thu Oct  9 18:22:28 2014 
** Last Update Sat Oct 11 23:07:15 2014 
*/

#include "exception.h"
#include "map.h"

void		map_init(s_map* map, const s_map_configs* configs)
{
  unsigned int	i;
  unsigned int	chunks_number;

  chunks_number = configs->longer * configs->larger;
  map->longer = configs->longer;
  map->larger = configs->larger;
  MALLOC(map->chunks, sizeof(s_chunk) * chunks_number);

  for (i = 0; i < chunks_number; ++i)
    chunk_init(&map->chunks[i]);
}
