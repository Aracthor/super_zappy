/*
** exception.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 20:02:07 2014 
** Last Update Sun Oct  5 04:27:40 2014 
*/

#ifndef EXCEPTION_H_
# define EXCEPTION_H_

# define FROM_EXCEPTION_STRUCTURE(exception)	(((int)exception.arg << 16) | (int)exception.id)

typedef struct __attribute__((packed))	exception
{
  unsigned short	id;
  unsigned short	arg;
}			s_exception;

typedef enum	exception_id
{
  exception_nothing,
  exception_bad_alloc,
  exception_bad_flag,
  exception_bad_param,
  exception_bad_param_arg,
  exception_not_enough_teams,
  exception_syscall,
  exception_mutex,
  exception_cond_var,
  exception_thread,
  exceptions_number
}		e_exception_id;

typedef int	(*t_exception_function)(unsigned short arg);

typedef int	t_exception;

/* handle.c */
int	exception_handle(t_exception exception);
int	exception_problem();

# include "exception/allocs.h"
# include "exception/cond_var.h"
# include "exception/keywords.h"
# include "exception/mutex.h"
# include "exception/param.h"
# include "exception/syscall.h"
# include "exception/thread.h"

#endif /* !EXCEPTION_H_ */
