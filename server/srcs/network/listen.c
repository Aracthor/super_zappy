/*
** listen.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 06:55:53 2014 
** Last Update Sun Oct  5 14:23:23 2014 
*/

#include <unistd.h>

#include "client.h"
#include "network.h"

#include "output.h"

void		network_handle_new_client(s_network* network)
{
  s_client	new_client;

  client_init(&new_client, network->socket);
  network->max_fd = MAX(network->max_fd, new_client.socket);

  /* Add to client list */
  mutex_lock(&network->clients.mutex);
  {
    push_front(&network->clients.data, &new_client, sizeof(s_client));
    client_init_thread((s_client *)network->clients.data->data);
  }
  mutex_unlock(&network->clients.mutex);
     
}

static void	network_add_client_fds(s_network* network, fd_set* fd_sets)
{
  s_list*	client;

  for (client = network->clients.data; client != NULL; client = client->next)
    FD_SET(((s_client*)client->data)->socket, &fd_sets[0]);
}

void	network_prepare_fds(s_network* network, fd_set* fd_sets)
{
  FD_ZERO(&fd_sets[0]);
  FD_ZERO(&fd_sets[1]);
  FD_SET(network->socket, &fd_sets[0]);
  FD_SET(STDIN_FILENO, &fd_sets[0]);
  network_add_client_fds(network, fd_sets);
}
