/*
** cond_var.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 04:28:53 2014 
** Last Update Sun Oct  5 04:30:37 2014 
*/

#include "exception.h"
#include "output.h"

static void	empl_error_messages(char** messages)
{
  messages[exception_cond_var_create]	= "Failed to create cond_var.";
  messages[exception_cond_var_delete]	= "Failed to delete cond_var.";
  messages[exception_cond_var_signal]	= "Failed to signal cond_var.";
  messages[exception_cond_var_wait]	= "Failed to wait cond_var.";
}

int	exception_cond_var_handling(unsigned short arg)
{
  char*	messages[exceptions_cond_var_number];
  int	return_value;

  empl_error_messages(messages);

  if (arg >= exceptions_cond_var_number)
    return_value = exception_problem();
  else
    {
      error_message("%s\n", messages[arg]);
      return_value = 1;
    }

  return (return_value);
}
