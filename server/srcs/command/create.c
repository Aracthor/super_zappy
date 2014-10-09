/*
** create.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Tue Oct  7 16:22:30 2014 
** Last Update Tue Oct  7 16:22:51 2014 
*/

#include "command.h"

void	create_order(s_order* order, char* code, unsigned int args_number, unsigned int id)
{
  order->code = code;
  order->args_number = args_number;
  order->command_id = id;
}
