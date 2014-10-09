/*
** create.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Wed Oct  8 13:53:11 2014 
** Last Update Wed Oct  8 13:53:43 2014 
*/

#include "action.h"

void	create_action(s_action* action, unsigned int id,
		      t_action_arg arg, unsigned int remaining_time)
{
  action->id = id;
  action->arg = arg;
  action->remaining_time = remaining_time;
}
