/*
** print.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Wed Oct  8 14:15:05 2014 
** Last Update Wed Oct  8 17:34:36 2014 
*/

#include <string.h>

#include "client.h"
#include "output.h"

void	client_print_received(s_client* client, const char* line)
{
  if (IS_AT_LEAST_ONE_PACKET_DEBUG)
    {
      if (client->type == graphical)
	{
	  RECEIVE_GRAPHICAL_PACKET_MESSAGE(client->socket, line);
	}
      else if (client->type == ia)
	{
	  RECEIVE_IA_PACKET_MESSAGE(client->socket, line);
	}
    }
}

void	client_print_sent(s_client* client, const char* line, unsigned int size)
{
  char	buffer[BUFFER_SIZE];

  if (IS_AT_LEAST_ONE_PACKET_DEBUG)
    {
      strncpy(buffer, line, size);
      buffer[size] = '\0';
      if (client->type == graphical)
	{
	  SEND_GRAPHICAL_PACKET_MESSAGE(client->socket, buffer);
	}
      else if (client->type == ia)
	{
	  SEND_IA_PACKET_MESSAGE(client->socket, buffer);
	}
    }
}
