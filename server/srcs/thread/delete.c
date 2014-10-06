/*
** delete.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 04:33:44 2014 
** Last Update Sun Oct  5 04:41:05 2014 
*/

#include "exception.h"
#include "thread.h"

#if (SYSTEM == WINDOWS)
# error "thread/delete.c for windows TODO"

#elif (SYSTEM == OSX)
# error "thread/delete.c for osx TODO"

#elif (SYSTEM == UNIX)
void	        thread_delete(s_thread* thread)
{
  s_exception	exception;

  if (pthread_cancel(*thread))
    {
      exception.id = exception_thread;
      exception.arg = exception_thread_delete;
      throw (FROM_EXCEPTION_STRUCTURE(exception));
    }
}
#endif /* (SYSTEM == WINDOWS */
