/*
** see_what_happened.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 08:43:31 2014 
** Last Update Wed Oct  8 17:45:24 2014 
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
  s_list*	client;
  void*		client_to_delete;

  client = server->network.clients.data;
  while (client != NULL)
    {
      if (((s_client*)client->data)->type == dead)
	{
	  mutex_lock(&server->network.clients.mutex);
	  {
	    client_to_delete = client->data;
	    client = client->next;
	    pop_cond(&server->network.clients.data, client_to_delete,
		     &is_elem, &client_delete_from_list);
	  }
	  mutex_unlock(&server->network.clients.mutex);
	}
      else
	client = client->next;
    }
	
}

void	server_see_what_happened(s_server* server, fd_set* fd_sets)
{
  check_new_connection(server, fd_sets);
  check_who_told_something(server, fd_sets);
  check_for_deads(server);
}
