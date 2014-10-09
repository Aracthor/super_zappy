/*
** output.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 23:54:48 2014 
** Last Update Wed Oct  8 14:49:39 2014 
*/

#include <stdio.h>
#include <stdarg.h>

#include "output.h"

void		error_message(const char* message, ...)
{
  va_list	args;
  char		buffer[BUFFER_OUTPUT_SIZE];

  va_start(args, message);
  {
    vsnprintf(buffer, BUFFER_OUTPUT_SIZE, message, args);
    fprintf(stderr, "%s%s%s", ERROR_OUTPUT, buffer, NORMAL_OUTPUT);
  }
  va_end(args);
}

void		server_intern_action_message(const char* message, ...)
{
  va_list	args;
  char		buffer[BUFFER_OUTPUT_SIZE];

  va_start(args, message);
  {
    vsnprintf(buffer, BUFFER_OUTPUT_SIZE, message, args);
    fprintf(stderr, "%s%s%s", SERVER_INTERN_ACTION_OUTPUT, buffer, NORMAL_OUTPUT);
  }
  va_end(args);
}

void		connection_message(const char* message, ...)
{
  va_list	args;
  char		buffer[BUFFER_OUTPUT_SIZE];

  va_start(args, message);
  {
    vsnprintf(buffer, BUFFER_OUTPUT_SIZE, message, args);
    printf("%s%s%s", CONNECTION_OUTPUT, buffer, NORMAL_OUTPUT);
  }
  va_end(args);
}


void	receive_graphical_packet_message(int id, const char* packet)
{
  printf("%smessage from %d\t: %s%s",
	 RECEIVE_GRAPHICAL_PACKET_OUTPUT, id, packet, NORMAL_OUTPUT);
}

void    send_graphical_packet_message(int id, const char* packet)
{
  printf("%smessage to %d\t: %s%s",
	 SEND_GRAPHICAL_PACKET_OUTPUT, id, packet, NORMAL_OUTPUT);
}

void	receive_ia_packet_message(int id, const char* packet)
{
  printf("%smessage from %d\t: %s%s",
	 RECEIVE_IA_PACKET_OUTPUT, id, packet, NORMAL_OUTPUT);
}

void    send_ia_packet_message(int id, const char* packet)
{
  printf("%smessage to %d\t: %s%s",
	 SEND_IA_PACKET_OUTPUT, id, packet, NORMAL_OUTPUT);
}
