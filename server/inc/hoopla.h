/*
** hoopla.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Thu Oct  9 10:11:38 2014 
** Last Update Sun Oct 12 00:13:12 2014 
*/

#ifndef HOOPLA_H_
# define HOOPLA_H_

# define MAX_HEIGHT	(100)

typedef enum	ground_type
{
  ground_snow,
  ground_bare,
  ground_tundra,
  ground_taiga,
  ground_shrubland,
  ground_rocky_desert,
  ground_temperate_jungle,
  ground_temperate_forest,
  ground_tallgrass,
  ground_grassland,
  ground_plain,
  ground_desert,
  ground_tropical_jungle,
  ground_tropical_forest,
  ground_breach,
  ground_ocean,
  grounds_number
}		e_ground_type;

typedef enum	item_id
{
  item_none,
  items_number
}		e_item_id;

typedef enum    object_id
{
  object_none,
  objects_number
}		e_object_id;

typedef unsigned int	e_player_id;

typedef struct	hoopla
{
  e_ground_type	ground_type;
  unsigned int	height;
  e_item_id	item_id;
  unsigned int	item_number;
  e_object_id	object_id;
  unsigned int	player_id;
}		s_hoopla;

#endif /* !HOOPLA_H_ */
