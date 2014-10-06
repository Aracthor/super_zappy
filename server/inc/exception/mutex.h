/*
** mutex.h<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 03:27:15 2014 
** Last Update Sun Oct  5 04:58:53 2014 
*/

#ifndef EXCEPTION_MUTEX_H_
# define EXCEPTION_MUTEX_H_

# define MUTEX_EXCEPTION(id, error)	((id << 24) | (error << 16) | exception_mutex)

typedef enum	exception_mutex
{
  exception_mutex_create,
  exception_mutex_delete,
  exception_mutex_lock,
  exception_mutex_trylock,
  exception_mutex_unlock,
  exceptions_mutex_number
}		e_exception_mutex;

/* mutex.c */
int	exception_mutex_handling(unsigned short arg);

#endif /* !EXCEPTION_MUTEX_H_ */
