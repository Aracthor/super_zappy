/*
** edit.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 06:10:24 2014 
** Last Update Thu Oct  9 16:49:34 2014 
*/

#include <string.h>

#include "buffer.h"

void		buffer_add(s_buffer* buffer, const char* message)
{
  unsigned int	size;

  size = strlen(message);
  memcpy(&buffer->data[buffer->full], message, size);
  buffer->full += size;
  buffer->data[buffer->full] = '\0';
}

void	buffer_sub(s_buffer* buffer, unsigned int size)
{
  memmove(buffer->data, &buffer->data[size], size);
  buffer->full -= size;
  buffer->data[buffer->full] = '\0';
}
