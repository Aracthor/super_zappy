/*
** client.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 02:06:52 2014 
** Last Update Mon Oct  6 08:36:53 2014 
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include "boolean.h"
# include "buffer.h"
# include "client_thread.h"
# include "socket.h"

# define BUFFER_SIZE	(0x1000)

typedef enum		client_type
{
  unknown,
  ia,
  graphical,
  dead
}			e_client_type;

typedef struct		client
{
  t_socket		socket;
  e_client_type	        type;
  s_buffer		input_buffer;
  s_buffer		output_buffer;
  s_client_thread	thread;
  bool			iminent_abort;
}			s_client;

/* init.c */
void	client_init(s_client* client, t_socket server_socket);
void	client_init_thread(s_client* client);

/* interprete.c */
void	client_interprete(s_client* client);

/* send.c */
void	client_add_to_send(s_client* client, char* message);

/* transfer.c */
void	client_recv(s_client* client);
void	client_send(s_client* client);

/* delete.c */
void	client_delete(s_client* client);
void	client_delete_from_list(void* client);

#endif /* !CLIENT_H_ */
