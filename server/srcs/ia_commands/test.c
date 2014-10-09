/*
** test.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Wed Oct  8 13:46:39 2014 
** Last Update Wed Oct  8 13:56:14 2014 
*/

#include <stdlib.h>

#include "ia_commands.h"

bool	ia_test(const s_server* server, const s_args* args, s_action* action)
{
  (void)(server);
  create_action(action, 0, atoi(args->data[1]), 10);

  return (true);
}
