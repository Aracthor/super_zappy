/*
** params.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 20:44:20 2014 
** Last Update Sun Oct  5 00:12:51 2014 
*/

#include "configs.h"
#include "exception.h"
#include "output.h"

static void	empl_params_tab(char **messages)
{
  messages[exception_param_port] = "port";
  messages[exception_param_speed] = "speed";
  messages[exception_param_teams] = "teams";
  messages[exception_param_map_longer] = "map longer";
  messages[exception_param_map_larger] = "map larger";
}

int	exception_bad_flag_handling(unsigned short arg)
{
  (void)(arg);
  error_message("Invalid flag.\n");
  return (1);
}

int	exception_bad_param_handling(unsigned short arg)
{
  (void)(arg);
  error_message("Invalid param.\n");
  return (1);
}

int	exception_bad_param_arg_handling(unsigned short arg)
{
  int	return_value;
  char*	params[exceptions_param_number];

  if (arg > exceptions_param_number)
    return_value = exception_problem();
  else
    {
      empl_params_tab(params);
      error_message("Invalid argument for param %s.\n", params[arg]);
      return_value = 1;
    }
  return (return_value);
}

int	exception_not_enough_teams_handling(unsigned short arg)
{
  (void)(arg);
  error_message("Not enough teams, minimum is %d.\n", TEAMS_NUMBER_MIN);
  return (1);
}
