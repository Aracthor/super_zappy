/*
** unlock.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 04:38:52 2014 
** Last Update Sun Oct  5 04:57:54 2014 
*/

#include "exception.h"
#include "mutex.h"

#if (SYSTEM == WINDOWS)
# error "mutex/unlock.c for windows TODO"

#elif (SYSTEM == OSX)
# error "mutex/unlock.c for osx TODO"

#elif (SYSTEM == UNIX)
void		mutex_unlock(s_mutex* mutex)
{
  int		error;

  error = pthread_mutex_unlock(mutex);
  if (error)
    throw (MUTEX_EXCEPTION(exception_mutex_unlock, error));
}
#endif /* (SYSTEM == WINDOWS */
