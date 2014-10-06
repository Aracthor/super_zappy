/*
** init.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 23:49:27 2014 
** Last Update Sun Oct  5 08:31:42 2014 
*/

#include <string.h>

#include "server.h"

void	server_init(s_server* server, s_configs* configs)
{
  network_init(&server->network, configs->port);
  graphical_thread_init(&server->graphical_thread, server);

  memcpy(&server->teams, &configs->teams, sizeof(s_teams));
  server->speed = configs->speed;
}
