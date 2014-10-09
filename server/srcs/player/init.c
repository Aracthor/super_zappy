/*
** init.c<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Wed Oct  8 10:35:23 2014 
** Last Update Wed Oct  8 11:21:04 2014 
*/

#include "action.h"
#include "player.h"

void	player_init(s_player* player, unsigned int team_id)
{
  player->team_id = team_id;
  pool_init(&player->actions_queue, sizeof(s_action), MAX_WAITING_ACTIONS);
}
