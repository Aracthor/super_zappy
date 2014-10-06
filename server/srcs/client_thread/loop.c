/*
** loop.c<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 07:36:38 2014 
** Last Update Sun Oct  5 14:18:59 2014 
*/

#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "client.h"
#include "client_thread.h"
#include "output.h"
#include "server.h"

static void	handle_client(s_client* client)
{
  client_recv(client);
  client_send(client);
}

void*		client_thread_loop(void* data)
{
  s_client*	client;

  client = (s_client*)data;

  server_intern_action_message("Client thread for client %d started !\n", client->socket);
  {
    while (client->thread.loop)
      {
	if (client->input_buffer.full == false && client->output_buffer.full == false)
	  cond_var_wait(&client->thread.cond_var);
	if (client->thread.loop && client->type != dead)
	  handle_client(client);
      }
  }
  server_intern_action_message("Client thread for client %d ended !\n", client->socket);

  return (NULL);
}
