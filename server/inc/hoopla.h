/*
** hoopla.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Thu Oct  9 10:11:38 2014 
** Last Update Thu Oct  9 11:41:52 2014 
*/

#ifndef HOOPLA_H_
# define HOOPLA_H_

typedef enum	ground_type
{
  ground_snow,
  ground_tundra,
  ground_bare,
  ground_temperate_jungle,
  ground_temperate_forest,
  ground_scorched_desert,
  ground_tropical_jungle,
  ground_tropical_forest,
  ground_hot_desert,
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
  e_item_id	item_id;
  e_object_id	object_id;
  e_player_id	player_id;
}		s_hoopla;

#endif /* !HOOPLA_H_ */
