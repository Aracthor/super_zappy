/*
** syscall.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 00:49:33 2014 
** Last Update Sun Oct  5 07:07:19 2014 
*/

#include <errno.h>
#include <stddef.h>
#include <string.h>

#include "exception.h"
#include "output.h"

static void	empl_syscalls_tab(char** syscalls)
{
  syscalls[exception_syscall_accept]	= "accept";
  syscalls[exception_syscall_close]	= "close";
  syscalls[exception_syscall_bind]	= "bind";
  syscalls[exception_syscall_listen]	= "listen";
  syscalls[exception_syscall_select]	= "select";
  syscalls[exception_syscall_socket]	= "socket";
}

static char*	get_syscall(e_exception_syscall id)
{
  char*		syscalls[exceptions_syscall_number];
  char*		syscall;

  empl_syscalls_tab(syscalls);

  if (id >= exceptions_syscall_number)
    syscall = NULL;
  else
    syscall = syscalls[id];

  return (syscall);
}

int	exception_syscall_handling(unsigned short arg)
{
  char*	syscall;
  char*	error;
  int	return_value;

  syscall = get_syscall((arg & 0xFF00) >> 8);
  error = strerror(arg & 0x00FF);

  if (syscall == NULL || error == NULL)
    return_value = exception_problem();
  else
    {
      error_message("Syscall %s failed because %s.\n", syscall, error);
      return_value = 1;
    }

  return (return_value);
}
