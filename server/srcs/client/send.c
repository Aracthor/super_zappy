/*
** send.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 05:57:21 2014 
** Last Update Wed Oct  8 14:47:10 2014 
*/

#include <string.h>

#include "client.h"
#include "output.h"

void	client_add_to_send(s_client* client, char* message)
{
  if (strlen(message) + 1 + client->output_buffer.full > BUFFER_SIZE)
    error_message("Too many data on output buffer for client %d.\n", client->socket);
  else
    {
      mutex_lock(&client->thread.mutex);
      {
	buffer_add(&client->output_buffer, message);
	buffer_add(&client->output_buffer, "\n");
      }
      mutex_unlock(&client->thread.mutex);
    }
}

bool	client_prepare_action(s_client* client, s_action* action)
{
  bool	possible;

  possible = (POOL_IS_FULL(&client->player.actions_queue) == false);

  if (possible == false)
    error_message("Action queue is full for client %d.\n", client->socket);
  else
    {
      mutex_lock(&client->thread.mutex);
      {
	pool_push_back(&client->player.actions_queue, action);
      }
      mutex_unlock(&client->thread.mutex);
    }

  return (possible);
}
