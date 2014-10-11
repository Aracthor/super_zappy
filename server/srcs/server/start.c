/*
** start.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 05:07:04 2014 
** Last Update Fri Oct 10 21:19:28 2014 
*/

#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#include "exception.h"
#include "output.h" /* DEBUG */
#include "server.h"

static void	server_calc_timeout(s_server* server, struct timeval* elapsed_time,
				    struct timeval* timeout)
{
  timeout->tv_sec = server->speed / 1000000 - elapsed_time->tv_sec;
  timeout->tv_usec = server->speed % 1000000 - elapsed_time->tv_usec;
  if (timeout->tv_usec < 0)
    timeout->tv_usec = 0;
}

static bool		server_loop(s_server* server, struct timeval* elapsed_time)
{
  struct timeval	timeout;
  fd_set		fd_sets[2];
  bool			continue_loop;

  /* Prepare select args */
  server_calc_timeout(server, elapsed_time, &timeout);
  network_prepare_fds(&server->network, fd_sets);

  /* THAT syscall */
  if (select(server->network.max_fd + 1, &fd_sets[0], &fd_sets[1], NULL, &timeout) == -1)
    {
      error_message("%d.%d\n", timeout.tv_sec, timeout.tv_usec);
      throw (SYSCALL_EXCEPTION(exception_syscall_select));
    }

  /* Check standart input for manual abort */
  continue_loop = !FD_ISSET(STDIN_FILENO, &fd_sets[0]);
  if (continue_loop)
    server_see_what_happened(server, fd_sets);

  return (continue_loop);
}

static void	calc_elapsed_time(struct timeval* before,
				  struct timeval* after,
				  struct timeval* elapsed_time,
				  unsigned int speed)
{
  elapsed_time->tv_sec = after->tv_sec - before->tv_sec - speed / 1000000;
  elapsed_time->tv_usec = after->tv_usec - before->tv_usec - speed % 1000000;

  if ((int)after->tv_usec < (int)before->tv_usec)
    {
      elapsed_time->tv_sec -= 1;
      elapsed_time->tv_usec += 1000000;
    }
}

void			server_start(s_server* server)
{
  struct timeval	before;
  struct timeval	after;
  struct timeval	elapsed_time;
  bool			loop;

  loop = true;
  memset(&elapsed_time, 0, sizeof(elapsed_time));

  while (loop)
    {
      gettimeofday(&before, NULL);
      loop = server_loop(server, &elapsed_time);
      gettimeofday(&after, NULL);
      calc_elapsed_time(&before, &after, &elapsed_time, server->speed);
    }
}
