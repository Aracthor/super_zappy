/*
** init.c<3> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 03:52:02 2014 
** Last Update Sun Oct  5 03:56:40 2014 
*/

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stddef.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "exception.h"
#include "network.h"
#include "socket.h"

#if (SYSTEM == WINDOWS)
# error "socket/init.c for windows TODO"

#elif (SYSTEM == OSX)
# error "socket/init.c for osx TODO"

#elif (SYSTEM == UNIX)
void		socket_init(t_socket* socket_fd, unsigned int port)
{
  struct protoent*	pe;
  struct sockaddr_in	s_in;
  int			useless_int;

  /* Init structures */
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  pe = getprotobyname("TCP");
  useless_int = 1;

  /* Create socket */
  *socket_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (*socket_fd == -1 ||
      setsockopt(*socket_fd, SOL_SOCKET, SO_REUSEADDR, &useless_int, sizeof(int)) == -1)
    throw (SYSCALL_EXCEPTION(exception_syscall_socket));

  /* Bind socket */
  if (bind(*socket_fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    throw (SYSCALL_EXCEPTION(exception_syscall_bind));

  /* Listen on socket */
  if (listen(*socket_fd, MAX_LISTEN_CLIENTS) == -1)
    throw (SYSCALL_EXCEPTION(exception_syscall_listen));
}
#endif /* (SYSTEM == WINDOWS) */
