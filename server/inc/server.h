/*
** server.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 23:45:31 2014 
** Last Update Thu Oct  9 18:07:59 2014 
*/

#ifndef SERVER_H_
# define SERVER_H_

# include "command.h"
# include "configs.h"
# include "graphical_thread.h"
# include "map.h"
# include "network.h"

typedef struct		server
{
  /* Network part */
  s_network		network;
  s_graphical_thread	graphical_thread;

  /* Config part */
  s_teams		teams;
  unsigned int		speed;

  /* Big data */
  s_map			map;

  /* Array to get */
  s_order		graphical_orders[GRAPHICAL_ORDERS_NUMBER + 1];
  s_order		ia_orders[IA_ORDERS_NUMBER + 1];
  t_graphical_command	graphical_commands[GRAPHICAL_COMMANDS_NUMBER + 1];
  t_ia_command	        ia_commands[IA_COMMANDS_NUMBER + 1];
}			s_server;

/* init.c */
void	server_init(s_server* server, s_configs* configs);

/* start.c */
void	server_start(s_server* server);

/* see_what_happened.c */
void	server_see_what_happened(s_server* server, fd_set* fd_sets);

/* delete.c */
void	server_delete(s_server* server);

const s_server*	g_server;

#endif /* !SERVER_H_ */
