/*
** chunks.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct 12 00:19:05 2014 
** Last Update Sun Oct 12 00:40:35 2014 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graphical_commands.h"

static unsigned int	graphical_hoopla(s_hoopla* hoopla, unsigned int x, unsigned int y,
					 char* buffer)
{
  return (snprintf(buffer, BUFFER_SIZE,
		   "CAS %d %d %d %d %d %d %d %d\n",
		   x, y,
		   hoopla->ground_type, hoopla->height,
		   hoopla->item_id, hoopla->item_number,
		   hoopla->object_id, hoopla->player_id));
}

bool		get_graphical_hoopla(const s_server* server,
				     const s_args* args, char *buffer)
{
  unsigned int	x, y;
  s_chunk*	chunk;
  bool		correct;

  x = atoi(args->data[1]);
  y = atoi(args->data[2]);
  correct = (x < CHUNK_SIZE && y < CHUNK_SIZE);

  if (correct)
    {
      chunk = &server->map.chunks[y / CHUNK_SIZE * server->map.longer + x / CHUNK_SIZE];
      graphical_hoopla(&chunk->hooplas[y / CHUNK_SIZE][x / CHUNK_SIZE], x, y, buffer);
      buffer[strlen(buffer) - 1] = '\0';
    }

  return (correct);
}

bool		get_graphical_chunk(const s_server* server,
				    const s_args* args, char *buffer)
{
  s_chunk*	chunk;
  unsigned int	x, y;
  unsigned int	hx, hy;
  unsigned int	size;
  bool		correct;

  x = atoi(args->data[1]);
  y = atoi(args->data[2]);
  correct = (x < server->map.longer && y < server->map.larger);

  if (correct)
    {
      size = snprintf(buffer, BUFFER_SIZE, "CHK %d %d\n", x, y);
      chunk = &server->map.chunks[y * server->map.longer + x];

      for (hx = 0; hx < CHUNK_SIZE; ++hx)
	for (hy = 0; hy < CHUNK_SIZE; ++hy)
	  {
	    buffer += size;
	    size = graphical_hoopla(&chunk->hooplas[hy][hx],
				    x * CHUNK_SIZE + hx, y * CHUNK_SIZE + hy,
				    buffer);
	  }
      buffer[strlen(buffer) - 1] = '\0';
    }

  return (correct);
}
