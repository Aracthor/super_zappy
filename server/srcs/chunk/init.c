/*
** init.c<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct 11 23:08:25 2014 
** Last Update Sun Oct 12 00:14:39 2014 
*/

#include <stdlib.h>

#include "chunk.h"

static void	init_hoopla(s_hoopla* hoopla)
{
  hoopla->ground_type = random() % grounds_number;
  hoopla->height = random() % MAX_HEIGHT;
  hoopla->item_id = 0;
  hoopla->item_number = 0;
  hoopla->object_id = 0;
  hoopla->player_id = 0;
}

void		chunk_init(s_chunk* chunk)
{
  unsigned int	x, y;

  for (x = 0; x < CHUNK_SIZE; ++x)
    for (y = 0; y < CHUNK_SIZE; ++y)
      {
	init_hoopla(&chunk->hooplas[y][x]);
      }
}
