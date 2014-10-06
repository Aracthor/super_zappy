/*
** string_params.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 22:42:28 2014 
** Last Update Sun Oct  5 01:50:44 2014 
*/

#include "configs.h"
#include "exception.h"

static void	check_name(char** names, char* name, unsigned int number)
{
  s_exception	exception;
  unsigned int	i;

  for (i = 0; i < number; ++i)
    if (name == names[i])
      {
	exception.id = exception_bad_param_arg;
	exception.arg = exception_param_teams;
	throw (FROM_EXCEPTION_STRUCTURE(exception));
      }
}

void	add_team_name(char* name, s_configs* configs)
{
  check_name(configs->teams.names, name, configs->teams.number);
  ++configs->teams.number;
  REALLOC(configs->teams.names, sizeof(char*) * configs->teams.number);
  configs->teams.names[configs->teams.number - 1] = name;
}
