/*
** recognize.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Tue Oct  7 08:29:20 2014 
** Last Update Wed Oct  8 10:43:09 2014 
*/

#include <string.h>

#include "client.h"
#include "server.h"

static bool	make_graphical(s_client* client)
{
  client->type = graphical;

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
