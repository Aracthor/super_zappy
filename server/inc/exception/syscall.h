/*
** syscall.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 01:31:59 2014 
** Last Update Sun Oct  5 07:07:07 2014 
*/

#ifndef EXCEPTION_SYSCALL_H_
# define EXCEPTION_SYSCALL_H_

# include <errno.h>

# define SYSCALL_EXCEPTION(id)	((id << 24) | (errno << 16) | exception_syscall)

typedef enum	exception_syscall
{
  exception_syscall_accept,
  exception_syscall_bind,
  exception_syscall_close,
  exception_syscall_listen,
  exception_syscall_select,
  exception_syscall_socket,
  exceptions_syscall_number
}		e_exception_syscall;

/* syscall.c */
int	exception_syscall_handling(unsigned short arg);

#endif /* !EXCEPTION_SYSCALL_H_ */
