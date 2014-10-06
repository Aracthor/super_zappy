/*
** init.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 04:32:54 2014 
** Last Update Sun Oct  5 04:43:57 2014 
*/

#include <stddef.h>

#include "exception.h"
#include "thread.h"

#if (SYSTEM == WINDOWS)
# error "thread/init.c for windows TODO"

#elif (SYSTEM == OSX)
# error "thread/init.c for osx TODO"

#elif (SYSTEM == UNIX)
void		thread_init(s_thread* thread, t_thread_start thread_start, void* arg)
{
  s_exception	exception;

  if (pthread_create(thread, NULL, thread_start, arg))
    {
      exception.id = exception_thread;
      exception.arg = exception_thread_create;
      throw (FROM_EXCEPTION_STRUCTURE(exception));
    }
}
#endif /* (SYSTEM == WINDOWS */
