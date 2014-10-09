/*
** pool.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Wed Oct  8 09:43:01 2014 
** Last Update Wed Oct  8 11:16:45 2014 
*/

#ifndef POOL_H_
# define POOL_H_

# include "containers.h"
# include "debug.h"
# include "types.h"

# define POOL_IS_FULL(pool)	((pool)->elems == (pool)->max_elems)
# define POOL_IS_EMPTY(pool)	((pool)->elems == 0)
# define POOL_FREE_ELEM(pool)	((pool)->data + (pool)->size * (pool)->elems)

typedef struct	pool
{
  t_byte*	data;
  unsigned int	size;
  unsigned int	elems;
  unsigned int	max_elems;
}		s_pool;

/* init.c */
void	pool_init(s_pool* pool, unsigned int size, unsigned int max_elems);

/* edit.c */
void	pool_push_front(s_pool* pool, const void* data);
void	pool_push_back(s_pool* pool, const void* data);
void	pool_pop_front(s_pool* pool, t_delete_fun delete_function);
void	pool_pop_back(s_pool* pool, t_delete_fun delete_function);

/* delete.c */
void	pool_delete(s_pool* pool, t_delete_fun delete_function);

#endif /* !POOL_H_ */
