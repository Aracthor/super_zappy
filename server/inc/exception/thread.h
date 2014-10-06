/*
** thread.h<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 03:28:24 2014 
** Last Update Sun Oct  5 04:44:23 2014 
*/

#ifndef EXCEPTION_THREAD_H_
# define EXCEPTION_THREAD_H_

typedef enum	exception_thread
{
  exception_thread_create,
  exception_thread_delete,
  exception_thread_join,
  exceptions_thread_number
}		e_exception_thread;

/* thread.c */
int	exception_thread_handling(unsigned short arg);

#endif /* !EXCEPTION_THREAD_H_ */
