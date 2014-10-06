/*
** init.c<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 02:11:46 2014 
** Last Update Mon Oct  6 08:35:30 2014 
*/

#include <arpa/inet.h>
#include <string.h>

#include "client.h"
#include "exception.h"
#include "output.h"

void			client_init(s_client* client, t_socket server_socket)
{
  struct sockaddr_in    infos;
  socklen_t		size;

  /* Empl buffers */
  memset(client, 0, sizeof(s_client));
  memset(&infos, 0, sizeof(infos));

  /* Create socket */
  size = sizeof(infos);
  client->socket = accept(server_socket, (struct sockaddr*)&infos, &size);
  if (client->socket == -1)
    throw (SYSCALL_EXCEPTION(exception_syscall_accept));
  connection_message("Client connected with domain %s, id attribued : %d.\n",
		     inet_ntoa(infos.sin_addr), client->socket);
}

void	client_init_thread(s_client* client)
{
  client_thread_init(&client->thread, client);
}
