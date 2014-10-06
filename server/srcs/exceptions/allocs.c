/*
** allocs.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 23:00:09 2014 
** Last Update Sun Oct  5 00:05:02 2014 
*/

#include "exception.h"
#include "output.h"

int	exception_bad_alloc_handling(unsigned short arg)
{
  (void)(arg);
  error_message("Malloc or Calloc failed.\n");
  return (1);
}
