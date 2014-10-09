/*
** delete.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Wed Oct  8 09:51:09 2014 
** Last Update Wed Oct  8 11:18:36 2014 
*/

#include "exception.h"
#include "pool.h"

static void	delete_data(s_pool* pool, t_delete_fun delete_function)
{
  t_byte*	elem;
  unsigned int	i;

  elem = pool->data;
  i = 0;

  while (i < pool->elems)
    {
      delete_function(elem);
      elem += pool->size;
      ++i;
    }
}

void	pool_delete(s_pool* pool, t_delete_fun delete_function)
{
  if (delete_function != NULL)
    delete_data(pool, delete_function);
  FREE(pool->data);
}
