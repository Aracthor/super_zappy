/*
** init.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 03:20:41 2014 
** Last Update Sun Oct  5 04:58:41 2014 
*/

#include <stddef.h>

#include "exception.h"
#include "mutex.h"

#if (SYSTEM == WINDOWS)
# error "mutex/init.c for windows TODO"

#elif (SYSTEM == OSX)
# error "mutex/init.c for osx TODO"

#elif (SYSTEM == UNIX)
void	mutex_init(s_mutex* mutex)
{
  int	error;

  error = pthread_mutex_init(mutex, NULL);
  if (error)
    throw (MUTEX_EXCEPTION(exception_mutex_create, error));
}
#endif /* (SYSTEM == WINDOWS */
