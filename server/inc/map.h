/*
** map.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Thu Oct  9 18:03:35 2014 
** Last Update Thu Oct  9 18:22:33 2014 
*/

#ifndef MAP_H_
# define MAP_H_

# include "configs.h"
# include "hoopla.h"

typedef struct	map
{
  unsigned int	longer;
  unsigned int	larger;
  s_hoopla*	hooplas;
}		s_map;

/* init.c */
void	map_init(s_map* map, const s_map_configs* configs);

/* delete.c */
void	map_delete(s_map* map);

#endif /* !MAP_H_ */
