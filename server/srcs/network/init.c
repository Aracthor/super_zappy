/*
** init.c<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 23:50:21 2014 
** Last Update Sun Oct  5 07:01:58 2014 
*/

#include "network.h"
#include "output.h"

void	network_init(s_network* network, unsigned int port)
{
  server_intern_action_message("Starting server on port %d...\n", port);
  {
    socket_init(&network->socket, port);
    mutexed_list_init(&network->clients);
    network->max_fd = network->socket;
  }
  server_intern_action_message("Server started !\n");
}
