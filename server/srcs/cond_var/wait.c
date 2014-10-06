/*
** wait.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 04:25:34 2014 
** Last Update Sun Oct  5 04:37:32 2014 
*/

#include "exception.h"
#include "cond_var.h"

#if (SYSTEM == WINDOWS)
# error "cond_var/signal.c for windows TODO"

#elif (SYSTEM == OSX)
# error "cond_var/signal.c for osx TODO"

#elif (SYSTEM == UNIX)
void	        cond_var_wait(s_cond_var* cond_var)
{
  s_exception	exception;

  mutex_trylock(&cond_var->mutex);

  if (pthread_cond_wait(&cond_var->pthread_cond_var, &cond_var->mutex))
    {
      exception.id = exception_cond_var;
      exception.arg = exception_cond_var_wait;
      throw (FROM_EXCEPTION_STRUCTURE(exception));
    }
}
#endif /* (SYSTEM == WINDOWS */
