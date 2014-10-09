/*
** exception.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 20:11:06 2014 
** Last Update Wed Oct  8 11:05:14 2014 
*/

#include "exception.h"
#include "output.h"

static void	print_usage(char* argv0)
{
  error_message("Usage:%s\n"
		"\t[-p port]\n"
		"\t[-x map_longer]\n"
		"\t[-y map_larger]\n"
		"\t[-t speed]\n"
		"\t-n team1 team2 [team3]*\n",
		argv0);
}

static void	empl_functions_tab(t_exception_function* functions)
{
  functions[exception_bad_alloc]	= &exception_bad_alloc_handling;
  functions[exception_bad_flag]		= &exception_bad_flag_handling;
  functions[exception_bad_param]	= &exception_bad_param_handling;
  functions[exception_bad_param_arg]	= &exception_bad_param_arg_handling;
  functions[exception_not_enough_teams]	= &exception_not_enough_teams_handling;
  functions[exception_syscall]		= &exception_syscall_handling;
  functions[exception_mutex]		= &exception_mutex_handling;
  functions[exception_thread]		= &exception_thread_handling;
  functions[exception_container]	= &exception_container_handling;
}

int			exception_handle(t_exception data, char* argv0)
{
  s_exception		exception;
  t_exception_function	functions[exceptions_number];
  int			return_value;

  exception = *((s_exception*)&data);
  if (exception.id == exception_nothing || exception.id >= exceptions_number)
    {
      error_message("Something is wrong with exceptions...\n");
      return_value = 2;
    }
  else
    {
      empl_functions_tab(functions);
      return_value = functions[exception.id](exception.arg);
      if (return_value == 1 && IS_USAGE_EXCEPTION(exception.id))
	print_usage(argv0);
    }
  return (return_value);
}

int	exception_problem()
{
  error_message("Something is wrong with exception args...\n");
  return (2);
}
