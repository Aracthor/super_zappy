/*
** loop.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 05:28:22 2014 
** Last Update Sun Oct  5 14:16:25 2014 
*/

#include <string.h>

#include "output.h"
#include "server.h"

void	graphical_thread_send_message(s_graphical_thread* graphical_thread, char* message)
{
  mutex_lock(&graphical_thread->mutex);
  {
    strcpy(graphical_thread->data_to_send, message);
  }
  mutex_unlock(&graphical_thread->mutex);

  cond_var_signal(&graphical_thread->cond_var);
}

static void	send_message_to_everyone(s_server* server)
{
  s_list*	client;

  mutex_lock(&server->network.clients.mutex);
  mutex_lock(&server->graphical_thread.mutex);
  {
    for (client = server->network.clients.data; client != NULL; client = client->next)
      if (((s_client*)client->data)->type == graphical)
	client_add_to_send((s_client*)client->data, server->graphical_thread.data_to_send);
  }
  mutex_unlock(&server->graphical_thread.mutex);
  mutex_unlock(&server->network.clients.mutex);
}

void*		graphical_thread_loop(void* data)
{
  s_server*	server;

  server = (s_server*)data;

  server_intern_action_message("Graphical thread started !\n");
  {
    while (server->graphical_thread.loop)
      {
	cond_var_wait(&server->graphical_thread.cond_var);
	if (server->graphical_thread.loop)
	  send_message_to_everyone(server);
      }
  }
  server_intern_action_message("Graphical thread ended !\n");

  return (NULL);
}
