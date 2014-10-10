/*
** init.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 23:49:27 2014 
** Last Update Thu Oct  9 18:21:31 2014 
*/

#include <string.h>

#include "graphical_commands.h"
#include "ia_commands.h"

static void	empl_graphical_commands_table(t_graphical_command* commands)
{
  commands[chunk_description]	= NULL;
  commands[case_description]	= NULL;
  commands[player_description]	= NULL;
  commands[player_equipement]	= NULL;
  commands[player_taking]	= NULL;
  commands[player_putting]	= NULL;
  commands[team_description]	= (t_graphical_command)&get_graphical_team_description;
}

static void	empl_ia_commands_table(t_ia_command* commands)
{
  commands[0]	= (t_ia_command)&ia_test;
}

static void	empl_graphical_orders_table(s_order* orders)
{
  create_order(&orders[0], "CHK", 3, chunk_description);
  create_order(&orders[1], "CAS", 3, case_description);
  create_order(&orders[2], "PDC", 2, player_description);
  create_order(&orders[3], "TDC", 2, team_description);
  create_order(&orders[4], NULL, 0, 0);
}

static void	empl_ia_orders_table(s_order* orders)
{
  create_order(&orders[0], "YOLO",	2, 0);
  create_order(&orders[1], NULL,	0, 0);
}

static void	empl_commands_tables(s_server* server)
{
  empl_graphical_orders_table(server->graphical_orders);
  empl_ia_orders_table(server->ia_orders);
  empl_graphical_commands_table(server->graphical_commands);
  empl_ia_commands_table(server->ia_commands);
}

void	server_init(s_server* server, s_configs* configs)
{
  network_init(&server->network, configs->port);
  graphical_thread_init(&server->graphical_thread, server);

  memcpy(&server->teams, &configs->teams, sizeof(s_teams));
  server->speed = configs->speed;

  map_init(&server->map, &configs->map);

  empl_commands_tables(server);

  g_server = server;
}
