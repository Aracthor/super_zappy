/*
** send.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 14:05:30 2014 
** Last Update Mon Oct  6 08:38:26 2014 
*/

#include <sys/socket.h>
#include <sys/types.h>

#include "client.h"
#include "output.h"

static void	lose_connection(s_client* client)
{
  error_message("Connection lost with client %d.\n", client->socket);
  client->type = dead;
}

void		client_recv(s_client* client)
{
  ssize_t	recv_len;

  /* Syscall */
  recv_len = recv(client->socket,
		  &client->input_buffer.data[client->input_buffer.full],
		  BUFFER_SIZE - client->input_buffer.full,
		  MSG_DONTWAIT);

  /* Error */
  if (recv_len == -1)
    lose_connection(client);

  /* Nothing got */
  if (recv_len == 0 && client->iminent_abort == true)
    lose_connection(client);
  else
    client->iminent_abort = true;

  /* Something got */
  if (recv_len > 0)
    {
      client->input_buffer.full += recv_len;
      client->iminent_abort = false;
    }

  /* Try to read buffer */
  client_interprete(client);
}

static void	try_to_send_something(s_client* client)
{
  ssize_t	send_len;

  /* Syscall */
  send_len = send(client->socket,
		  client->output_buffer.data,
		  client->output_buffer.full,
		  MSG_DONTWAIT);

  /* Error */
  if (send_len == -1)
    lose_connection(client);

  /* Move */
  else if (send_len > 0)
    buffer_sub(&client->output_buffer, send_len);
}

void	client_send(s_client* client)
{
  mutex_lock(&client->thread.mutex);
  {
    if (client->output_buffer.full != false)
      try_to_send_something(client);
  }
  mutex_unlock(&client->thread.mutex);
}
