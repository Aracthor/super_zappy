/*
** delete.c<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 02:04:54 2014 
** Last Update Sun Oct  5 06:17:37 2014 
*/

#include "client.h"
#include "network.h"
#include "output.h"

void	network_delete(s_network* network)
{
  server_intern_action_message("Stopping server...\n");
  socket_delete(&network->socket);
  mutexed_list_delete(&network->clients, &client_delete_from_list);
  server_intern_action_message("Server stopped ! Program end imiment.\n");
}
