/*
** containers.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Wed Oct  8 11:01:39 2014 
** Last Update Wed Oct  8 11:21:46 2014 
*/

#include "exception.h"
#include "output.h"

static void	empl_problems_tab(char** problems)
{
  problems[exception_container_full]	= "Trying to push into a full container.";
  problems[exception_container_empty]	= "Trying to pop from an empty container.";
}

int	exception_container_handling(unsigned short arg)
{
  int	return_value;
  char* problems[exceptions_container_number];

  if (arg >= exceptions_container_number)
    return_value = exception_problem();
  else
    {
      empl_problems_tab(problems);
      error_message("%s", problems[arg]);
      return_value = 1;
    }
  return (return_value);
}
