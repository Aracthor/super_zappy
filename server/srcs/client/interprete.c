/*
** interprete.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Mon Oct  6 08:36:19 2014 
** Last Update Wed Oct  8 14:15:00 2014 
*/

#include <sys/socket.h>

#include "client.h"
#include "output.h"
#include "server.h"

static void	client_kick(s_client* client)
{
  error_message("Error with client %d, kicking him !\n", client->socket);
  send(client->socket, SERVER_KICK, sizeof(SERVER_KICK), 0);
  client_kill(client);
}

static bool		interprete_graphical_question(s_client* client, s_args* args)
{
  const s_server*       server = g_server;
  int			command_id;
  char			buffer[BUFFER_SIZE];
  bool			correct;

  command_id = find_order_id(server->graphical_orders, args);
  correct = (command_id >= 0);
  if (correct)
    {
      correct = server->graphical_commands[command_id](server, args, buffer);
      if (correct)
	client_add_to_send(client, buffer);
    }

  return (correct);
}

static bool		interprete_ia_action(s_client* client, s_args* args)
{
  const s_server*       server = g_server;
  s_action		action;
  int			command_id;
  bool			correct;
  bool			action_possible;

  command_id = find_order_id(server->ia_orders, args);
  correct = (command_id >= 0);
  if (correct)
    {
      action_possible = server->ia_commands[command_id](server, args, &action);
      if (action_possible)
	action_possible = client_prepare_action(client, &action);

      if (action_possible == false)
	client_add_to_send(client, IA_BAD_ORDER);
    }

  return (correct);
}

static bool	interprete_args(s_client* client, s_args* args)
{
  bool		interpreted;

  if (client->type == unknown)
    interpreted = client_recognize(client, args);
  else if (client->type == graphical)
    interpreted = interprete_graphical_question(client, args);
  else
    interpreted = interprete_ia_action(client, args);

  return (interpreted);
}

void		client_interprete(s_client* client)
{
  s_args	args;
  char		line[BUFFER_SIZE];
  bool		everything_is_ok;

  everything_is_ok = true;
  while (everything_is_ok &&
	 (buffer_get_next_line(&client->input_buffer, line)))
    {
      everything_is_ok = cut_line_in_args(line, &args);
      if (everything_is_ok)
	everything_is_ok = interprete_args(client, &args);
    }

  /* Something bad happened in parsing */
  if (everything_is_ok == false)
    client_kick(client);
}
