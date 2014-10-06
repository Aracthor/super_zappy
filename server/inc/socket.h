/*
** socket.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 03:49:10 2014 
** Last Update Sun Oct  5 04:15:28 2014 
*/

#ifndef SOCKET_H_
# define SOCKET_H_

# include "system.h"

# if (SYSTEM == WINDOWS)
#  include "socket/windows.h"
# elif (SYSTEM == OSX)
#  include "socket/osx.h"
#  error "socket.h for osx TODO"
# elif (SYSTEM == UNIX)
#  include "socket/unix.h"
# endif /* (SYSTEM == WINDOWS) */

/* init.c */
void	socket_init(t_socket* socket, unsigned int port);

/* delete.c */
void	socket_delete(t_socket* socket);

#endif /* !SOCKET_H_ */
