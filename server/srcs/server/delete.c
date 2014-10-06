/*
** delete.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 02:33:56 2014 
** Last Update Sun Oct  5 06:18:01 2014 
*/

#include "exception.h"
#include "server.h"

void	server_delete(s_server* server)
{
  graphical_thread_delete(&server->graphical_thread);

  network_delete(&server->network);

  FREE(server->teams.names);
}
