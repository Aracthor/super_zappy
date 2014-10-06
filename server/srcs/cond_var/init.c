/*
** init.c<3> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 04:18:52 2014 
** Last Update Sun Oct  5 04:22:27 2014 
*/

#include "cond_var.h"
#include "exception.h"

#if (SYSTEM == WINDOWS)
# error "cond_var/init.c for windows TODO"

#elif (SYSTEM == OSX)
# error "cond_var/init.c for osx TODO"

#elif (SYSTEM == UNIX)
void		cond_var_init(s_cond_var* cond_var)
{
  s_exception	exception;

  mutex_init(&cond_var->mutex);

  if (pthread_cond_init(&cond_var->pthread_cond_var, NULL))
    {
      exception.id = exception_cond_var;
      exception.arg = exception_cond_var_create;
      throw (FROM_EXCEPTION_STRUCTURE(exception));
    }
}
#endif /* (SYSTEM == WINDOWS */
