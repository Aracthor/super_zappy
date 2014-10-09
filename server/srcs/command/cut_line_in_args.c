/*
** cut_line_in_args.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Tue Oct  7 09:34:39 2014 
** Last Update Tue Oct  7 10:11:54 2014 
*/

#include <string.h>

#include "command.h"

bool		cut_line_in_args(char* line, s_args* args)
{
  char*		arg;
  unsigned int	pos;
  bool		line_ok;

  args->data[0] = strtok(line, ARGS_DELIMITER);
  pos = 1;
  line_ok = true;

  while (line_ok &&
	 (arg = strtok(NULL, ARGS_DELIMITER)) != NULL)
    {
      if (pos >= MAX_ARGS_NUMBER)
	line_ok = false;
      else
	{
	  args->data[pos] = arg;
	  ++pos;
	}
    }

  if (line_ok)
    args->number = pos;

  return (line_ok);
}
