/*
** player.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Tue Oct  7 12:23:13 2014 
** Last Update Wed Oct  8 11:19:41 2014 
*/

#ifndef PLAYER_H_
# define PLAYER_H_

# include "pool.h"

# define MAX_WAITING_ACTIONS	(10)

typedef struct	player
{
  s_pool	actions_queue;
  unsigned int	team_id;
}		s_player;

/* init.c */
void	player_init(s_player* player, unsigned int team_id);

/* delete.c */
void	player_delete(s_player* player);

#endif /* !PLAYER_H_ */
