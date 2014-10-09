/*
** edit.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Wed Oct  8 10:52:43 2014 
** Last Update Wed Oct  8 11:19:27 2014 
*/

#include <string.h>

#include "exception.h"
#include "pool.h"

static void	check_full_pool(s_pool* pool)
{
  s_exception	exception;

  if (POOL_IS_FULL(pool))
    {
      exception.id = exception_container;
      exception.arg = exception_container_full;
      throw (FROM_EXCEPTION_STRUCTURE(exception));
    }
}

static void	check_empty_pool(s_pool* pool)
{
  s_exception	exception;

  if (POOL_IS_EMPTY(pool))
    {
      exception.id = exception_container;
      exception.arg = exception_container_empty;
      throw (FROM_EXCEPTION_STRUCTURE(exception));
    }
}

void	pool_push_front(s_pool* pool, const void* data)
{
  if (_SECURE_CONTAINERS)
    check_full_pool(pool);

  memmove(pool->data + pool->size, pool->data, pool->size * pool->elems);
  memcpy(pool->data, data, pool->size);
  ++pool->elems;
}

void		pool_push_back(s_pool* pool, const void* data)
{
  t_byte*	elem;

  if (_SECURE_CONTAINERS)
    check_full_pool(pool);

  elem = POOL_FREE_ELEM(pool);
  memcpy(elem, data, pool->size);
  ++pool->elems;
}

void	pool_pop_front(s_pool* pool, t_delete_fun delete_function)
{
  if (_SECURE_CONTAINERS)
    check_empty_pool(pool);

  if (delete_function != NULL)
    delete_function(&pool->data[0]);

  memmove(pool->data, pool->data + pool->size, pool->size * (pool->elems - 1));
  --pool->elems;
}

void	pool_pop_back(s_pool* pool, t_delete_fun delete_function)
{
  if (_SECURE_CONTAINERS)
    check_empty_pool(pool);

  if (delete_function != NULL)
    delete_function(&pool->data[pool->elems - 1]);

  --pool->elems;
}
