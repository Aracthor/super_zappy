/*
** number_params.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 22:29:09 2014 
** Last Update Sun Oct  5 00:09:31 2014 
*/

#include <stdlib.h>

#include "configs.h"
#include "exception.h"

static unsigned int	read_number_param(char* arg, e_exception_param_arg exception_arg,
					  unsigned int min, unsigned int max)
{
  unsigned int		result;
  s_exception		exception;

  result = atoi(arg);
  if (result < min || result > max)
    {
      exception.id = exception_bad_param_arg;
      exception.arg = exception_arg;
      throw (FROM_EXCEPTION_STRUCTURE(exception));
    }
  return (result);
}

void	change_port(char* arg, s_configs* configs)
{
  configs->port = read_number_param(arg, exception_param_port, PORT_MIN, PORT_MAX);
}

void	change_speed(char* arg, s_configs* configs)
{
  configs->speed = read_number_param(arg, exception_param_speed, SPEED_MIN, SPEED_MAX);
}

void	change_map_longer(char* arg, s_configs* configs)
{
  configs->map.longer = read_number_param(arg, exception_param_port,
					  MAP_SIZE_MIN, MAP_SIZE_MAX);
}

void	change_map_larger(char* arg, s_configs* configs)
{
  configs->map.larger = read_number_param(arg, exception_param_port,
					  MAP_SIZE_MIN, MAP_SIZE_MAX);
}
