/*
** lock.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 04:38:11 2014 
** Last Update Sun Oct  5 04:57:27 2014 
*/

#include "exception.h"
#include "mutex.h"

#if (SYSTEM == WINDOWS)
# error "mutex/lock.c for windows TODO"

#elif (SYSTEM == OSX)
# error "mutex/lock.c for osx TODO"

#elif (SYSTEM == UNIX)
void		mutex_lock(s_mutex* mutex)
{
  int		error;

  error = pthread_mutex_lock(mutex);
  if (error)
    throw (MUTEX_EXCEPTION(exception_mutex_lock, error));
}
#endif /* (SYSTEM == WINDOWS */
