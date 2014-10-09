/*
** access.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Tue Oct  7 13:16:42 2014 
** Last Update Tue Oct  7 16:25:52 2014 
*/

#include <string.h>

#include "command.h"

static bool	order_match(const s_order* orders, const s_args* args)
{
  return (orders->args_number == args->number &&
	  !strcmp(orders->code, args->data[0]));
}

int	find_order_id(const s_order* orders, const s_args* args)
{
  int	id;

  id = 0;
  while (orders[id].args_number > 0
	 && order_match(&orders[id], args) == false)
    ++id;

  if (orders[id].args_number == 0)
    id = -1;
  else
    id = orders[id].command_id;

  return (id);
}
