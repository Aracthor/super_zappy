/*
** read.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Tue Oct  7 12:32:44 2014 
** Last Update Tue Oct  7 12:33:36 2014 
*/

#include <string.h>

#include "buffer.h"

bool		buffer_get_next_line(s_buffer* buffer, char* line)
{
  char*		next_endline;
  unsigned long	size;
  bool		new_line;

  next_endline = strchr(buffer->data, '\n');
  new_line = (next_endline != NULL);

  if (new_line)
    {
      *next_endline = '\0';
      strcpy(line, buffer->data);
      size = next_endline - buffer->data;
      buffer->full -= size + 1;
      memmove(buffer->data, buffer->data + size + 1, buffer->full);
    }

  return (new_line);
}
