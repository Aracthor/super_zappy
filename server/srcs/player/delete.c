/*
** delete.c<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Wed Oct  8 10:41:31 2014 
** Last Update Wed Oct  8 11:21:08 2014 
*/

#include <stddef.h>

#include "player.h"

void	player_delete(s_player* player)
{
  pool_delete(&player->actions_queue, NULL);
}
