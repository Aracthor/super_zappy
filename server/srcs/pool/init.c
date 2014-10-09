/*
** init.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Wed Oct  8 09:42:55 2014 
** Last Update Wed Oct  8 10:52:26 2014 
*/

#include <string.h>

#include "exception.h"
#include "pool.h"

void	pool_init(s_pool* pool, unsigned int size, unsigned int max_elems)
{
  MALLOC(pool->data, size * max_elems);
  memset(pool->data, 0, size * max_elems);
  pool->size = size;
  pool->elems = 0;
  pool->max_elems = max_elems;
}
