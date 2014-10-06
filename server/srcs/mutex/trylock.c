/*
** trylock.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 04:38:38 2014 
** Last Update Sun Oct  5 05:11:12 2014 
*/

#include "exception.h"
#include "mutex.h"

#if (SYSTEM == WINDOWS)
# error "mutex/trylock.c for windows TODO"

#elif (SYSTEM == OSX)
# error "mutex/trylock.c for osx TODO"

#elif (SYSTEM == UNIX)
bool	mutex_trylock(s_mutex* mutex)
{
  bool	locked;

  locked = pthread_mutex_trylock(mutex);
  return (locked);
}
#endif /* (SYSTEM == WINDOWS */
