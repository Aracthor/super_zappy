/*
** thread.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 03:36:41 2014 
** Last Update Sun Oct  5 04:44:39 2014 
*/

#include "exception.h"
#include "output.h"

static void	empl_error_messages(char** messages)
{
  messages[exception_thread_create]	= "Failed to create thread.";
  messages[exception_thread_delete]	= "Failed to delete thread.";
  messages[exception_thread_join]	= "Failed to join thread.";
}

int	exception_thread_handling(unsigned short arg)
{
  char*	messages[exceptions_thread_number];
  int	return_value;

  empl_error_messages(messages);

  if (arg >= exceptions_thread_number)
    return_value = exception_problem();
  else
    {
      error_message("%s\n", messages[arg]);
      return_value = 1;
    }

  return (return_value);
}
