/*
** server.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 23:45:31 2014 
** Last Update Sun Oct  5 08:44:08 2014 
*/

#ifndef SERVER_H_
# define SERVER_H_

# include "configs.h"
# include "graphical_thread.h"
# include "network.h"

typedef struct		server
{
  s_network		network;
  s_graphical_thread	graphical_thread;

  s_teams		teams;
  unsigned int		speed;
}			s_server;

/* init.c */
void	server_init(s_server* server, s_configs* configs);

/* start.c */
void	server_start(s_server* server);

/* see_what_happened.c */
void	server_see_what_happened(s_server* server, fd_set* fd_sets);

/* delete.c */
void	server_delete(s_server* server);

#endif /* !SERVER_H_ */
