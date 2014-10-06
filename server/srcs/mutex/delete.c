/*
** delete.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 03:37:55 2014 
** Last Update Sun Oct  5 05:13:01 2014 
*/

#include "exception.h"
#include "mutex.h"

#if (SYSTEM == WINDOWS)
# error "mutex/delete.c for windows TODO"

#elif (SYSTEM == OSX)
# error "mutex/delete.c for osx TODO"

#elif (SYSTEM == UNIX)
void	        mutex_delete(s_mutex* mutex)
{
  int		error;

  /* Assure it is not busy anymore */
  mutex_trylock(mutex);
  mutex_unlock(mutex);

  /* Delete it */
  error = pthread_mutex_destroy(mutex);
  if (error)
    throw (MUTEX_EXCEPTION(exception_mutex_delete, error));
}
#endif /* (SYSTEM == WINDOWS */
