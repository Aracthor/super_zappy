/*
** map.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Thu Oct  9 18:03:35 2014 
** Last Update Sat Oct 11 23:04:05 2014 
*/

#ifndef MAP_H_
# define MAP_H_

# include "chunk.h"
# include "configs.h"

typedef struct	map
{
  unsigned int	longer;
  unsigned int	larger;
  s_chunk*      chunks;
}		s_map;

/* init.c */
void	map_init(s_map* map, const s_map_configs* configs);

/* delete.c */
void	map_delete(s_map* map);

#endif /* !MAP_H_ */
