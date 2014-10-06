/*
** join.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 04:43:51 2014 
** Last Update Sun Oct  5 04:55:04 2014 
*/

#include "exception.h"
#include "thread.h"

#if (SYSTEM == WINDOWS)
# error "thread/join.c for windows TODO"

#elif (SYSTEM == OSX)
# error "thread/join.c for osx TODO"

#elif (SYSTEM == UNIX)
void*		thread_join(s_thread* thread)
{
  s_exception	exception;
  void*		retval;

  if (pthread_join(*thread, &retval))
    {
      exception.id = exception_thread;
      exception.arg = exception_thread_join;
      throw (FROM_EXCEPTION_STRUCTURE(exception));
    }

  return (retval);
}
#endif /* (SYSTEM == WINDOWS */
