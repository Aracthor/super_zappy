/*
** signal.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 04:22:48 2014 
** Last Update Sun Oct  5 04:37:24 2014 
*/

#include "exception.h"
#include "cond_var.h"

#if (SYSTEM == WINDOWS)
# error "cond_var/signal.c for windows TODO"

#elif (SYSTEM == OSX)
# error "cond_var/signal.c for osx TODO"

#elif (SYSTEM == UNIX)
void	        cond_var_signal(s_cond_var* cond_var)
{
  s_exception	exception;

  mutex_trylock(&cond_var->mutex);
  mutex_unlock(&cond_var->mutex);

  if (pthread_cond_signal(&cond_var->pthread_cond_var))
    {
      exception.id = exception_cond_var;
      exception.arg = exception_cond_var_signal;
      throw (FROM_EXCEPTION_STRUCTURE(exception));
    }
}
#endif /* (SYSTEM == WINDOWS */
