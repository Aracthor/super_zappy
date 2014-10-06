/*
** send.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 05:57:21 2014 
** Last Update Sun Oct  5 14:16:11 2014 
*/

#include <string.h>

#include "client.h"
#include "output.h"

void	client_add_to_send(s_client* client, char* message)
{
  if (strlen(message) + client->output_buffer.full > BUFFER_SIZE)
    error_message("Too many data on output buffer for client %d.\n", client->socket);
  else
    {
      mutex_lock(&client->thread.mutex);
      {
	buffer_add(&client->output_buffer, message);
      }
      mutex_unlock(&client->thread.mutex);
    }
}
