/*
** see_what_happened.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 08:43:31 2014 
** Last Update Sun Oct  5 14:23:39 2014 
*/

#include "server.h"

static void	check_new_connection(s_server* server, fd_set* fd_sets)
{
  if (FD_ISSET(server->network.socket, &fd_sets[0]))
    network_handle_new_client(&server->network);
}

static void	check_who_told_something(s_server* server, fd_set* fd_sets)
{
  s_list*	elem;
  s_client*	client;

  for (elem = server->network.clients.data; elem != NULL; elem = elem->next)
    {
      client = (s_client*)elem->data;
      if (FD_ISSET(client->socket, &fd_sets[0]))
	cond_var_signal(&client->thread.cond_var);
    }
}

static void	check_for_deads(s_server* server)
{
  s_list*	elem;

  for (elem = server->network.clients.data; elem != NULL; elem = elem->next)
    if (((s_client*)elem->data)->type == dead)
      {
	mutex_lock(&server->network.clients.mutex);
	{
	  pop_cond(&server->network.clients.data, elem->data,
		   &is_elem, &client_delete_from_list);
	}
	mutex_unlock(&server->network.clients.mutex);
      }
	
}

void	server_see_what_happened(s_server* server, fd_set* fd_sets)
{
  check_new_connection(server, fd_sets);
  check_who_told_something(server, fd_sets);
  check_for_deads(server);
}
