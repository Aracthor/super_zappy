/*
** delete.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 03:53:44 2014 
** Last Update Sun Oct  5 03:55:26 2014 
*/

#include <unistd.h>

#include "exception.h"
#include "socket.h"

#if (SYSTEM == WINDOWS)
# error "socket/init.c for windows TODO"

#elif (SYSTEM == OSX)
# error "socket/init.c for osx TODO"

#elif (SYSTEM == UNIX)
void		socket_delete(t_socket* socket)
{
  if (close(*socket) == -1)
    throw (SYSCALL_EXCEPTION(exception_syscall_close));

}
#endif /* (SYSTEM == WINDOWS) */
