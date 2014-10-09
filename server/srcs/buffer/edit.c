/*
** edit.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 06:10:24 2014 
** Last Update Wed Oct  8 14:48:50 2014 
*/

#include <string.h>

#include "buffer.h"

void		buffer_add(s_buffer* buffer, const char* message)
{
  unsigned int	size;

  size = strlen(message);
  memcpy(&buffer->data[buffer->full], message, size);
  buffer->full += size;
}

void	buffer_sub(s_buffer* buffer, unsigned int size)
{
  memmove(buffer->data, &buffer->data[size], size);
  buffer->full -= size;
}
