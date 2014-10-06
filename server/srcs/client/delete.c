/*
** delete.c<3> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 02:23:38 2014 
** Last Update Sun Oct  5 08:55:41 2014 
*/

#include <unistd.h>

#include "client.h"
#include "exception.h"
#include "output.h"

void	client_delete(s_client* client)
{
  socket_delete(&client->socket);
  connection_message("Client %d disconnected.\n", client->socket);
  client_thread_delete(&client->thread);
}

void	client_delete_from_list(void* client)
{
  client_delete((s_client*)client);
}
