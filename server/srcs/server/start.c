/*
** start.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 05:07:04 2014 
** Last Update Sun Oct  5 08:43:21 2014 
*/

#include <unistd.h>

#include "exception.h"
#include "server.h"

static void	server_calc_timeout(s_server* server, struct timeval* timeout)
{
  (void)(server);
  timeout->tv_sec = 10000;
  timeout->tv_usec = 10000;
}

static bool		server_loop(s_server* server)
{
  struct timeval	timeout;
  fd_set		fd_sets[2];
  bool			continue_loop;

  /* Prepare select args */
  server_calc_timeout(server, &timeout);
  network_prepare_fds(&server->network, fd_sets);

  /* THAT syscall */
  if (select(server->network.max_fd + 1, &fd_sets[0], &fd_sets[1], NULL, &timeout) == -1)
    throw (SYSCALL_EXCEPTION(exception_syscall_select));

  /* Check standart input for manual abort */
  continue_loop = !FD_ISSET(STDIN_FILENO, &fd_sets[0]);
  if (continue_loop)
    server_see_what_happened(server, fd_sets);

  return (continue_loop);
}

void	server_start(s_server* server)
{
  bool	loop;

  loop = true;
  while (loop)
    loop = server_loop(server);
}
