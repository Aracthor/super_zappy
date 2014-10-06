/*
** mutex.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 03:26:31 2014 
** Last Update Sun Oct  5 05:02:33 2014 
*/

#include <string.h>

#include "exception.h"
#include "output.h"

static void	empl_error_messages(char** messages)
{
  messages[exception_mutex_create]	= "Failed to create mutex";
  messages[exception_mutex_delete]	= "Failed to delete mutex";
  messages[exception_mutex_lock]	= "Failed to lock mutex";
  messages[exception_mutex_trylock]	= "Failed to trylock mutex";
  messages[exception_mutex_unlock]	= "Failed to unlock mutex";
}

static char*	get_error_message(e_exception_mutex id)
{
  char*		messages[exceptions_mutex_number];
  char*		message;

  empl_error_messages(messages);

  if (id >= exceptions_mutex_number)
    message = NULL;
  else
    message = messages[id];

  return (message);
}

int	exception_mutex_handling(unsigned short arg)
{
  char*	error;
  char*	code;
  int	return_value;

  error = get_error_message((arg & 0xFF00) >> 8);
  code = strerror(arg & 0x00FF);

  if (error == NULL || code == NULL)
    return_value = exception_problem();
  else
    {
      error_message("%s because %s\n", error, code);
      return_value = 1;
    }

  return (return_value);
}
