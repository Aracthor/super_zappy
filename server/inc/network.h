/*
** network.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 23:46:31 2014 
** Last Update Sun Oct  5 14:23:31 2014 
*/

#ifndef NETWORK_H_
# define NETWORK_H_

# include <sys/select.h>

# include "mutexed_list.h"
# include "socket.h"

# define MAX_LISTEN_CLIENTS	(42)

typedef struct		network
{
  t_socket		socket;
  s_mutexed_list	clients;
  int			max_fd;
}			s_network;

/* init.c */
void	network_init(s_network* network, unsigned int port);

/* listen.c */
void	network_handle_new_client(s_network* network);
void	network_prepare_fds(s_network* network, fd_set* fd_sets);

/* delete.c */
void	network_delete(s_network* network);

#endif /* !NETWORK_H_ */
