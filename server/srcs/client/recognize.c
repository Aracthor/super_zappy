/*
** recognize.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Tue Oct  7 08:29:20 2014 
** Last Update Sun Oct 12 00:44:06 2014 
*/

#include <stdio.h>
#include <string.h>

#include "client.h"
#include "output.h"
#include "server.h"

static bool		make_graphical(s_client* client)
{
  const s_server*	server = g_server;
  unsigned int		i;
  char			islands_parameters[BUFFER_SIZE];

  client->type = graphical;
  connection_message("Client %d is now a graphical client.\n", client->socket);

  snprintf(islands_parameters, BUFFER_SIZE, "ISL %d %d %d",
	   server->speed, server->map.longer, server->map.larger);
  client_add_to_send(client, islands_parameters);
  for (i = 0; i < server->teams.number; ++i)
    {
      snprintf(islands_parameters, BUFFER_SIZE, "TDC %d %s",
	       i, server->teams.names[i]);
      client_add_to_send(client, islands_parameters);
    }

  return (true);
}

static bool	make_ia(s_client* client, char* team_name)
{
  int		team_id;
  bool		client_is_correct;

  team_id = get_team_id(&g_server->teams, team_name);
  client_is_correct = (team_id != -1);

  if (client_is_correct)
    {
      client->type = ia;
      connection_message("Client %d is now a member of team %s.\n",
			 client->socket, team_name);
      player_init(&client->player, team_id);
    }

  return (client_is_correct);
}

bool	client_recognize(s_client* client, s_args* args)
{
  bool	client_is_correct;

  /* Graphical */
  if (!strcmp(args->data[0], GRAPHICAL_MESSAGE) && args->number == 1)
    client_is_correct = make_graphical(client);
  
  /* IA */
  else if (!strcmp(args->data[0], IA_MESSAGE) && args->number == 2)
    client_is_correct = make_ia(client, args->data[1]);

  /* Other */
  else
    client_is_correct = false;

  return (client_is_correct);
}
