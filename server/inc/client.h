/*
** client.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 02:06:52 2014 
** Last Update Wed Oct  8 14:20:29 2014 
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include "buffer.h"
# include "command.h"
# include "client_thread.h"
# include "player.h"
# include "socket.h"

# define CLIENT_KIND_NUMBER	(3)

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
  s_player		player;
}			s_client;

/* init.c */
void	client_init(s_client* client, t_socket server_socket);
void	client_init_thread(s_client* client);

/* interprete.c */
void	client_interprete(s_client* client);

/* print.c */
void	client_print_received(s_client* client, const char* line);
void	client_print_sent(s_client* client, const char* line, unsigned int size);

/* recognize.c */
bool	client_recognize(s_client* client, s_args* args);

/* send.c */
void	client_add_to_send(s_client* client, char* message);
bool	client_prepare_action(s_client* client, s_action* action);

/* transfer.c */
void	client_recv(s_client* client);
void	client_send(s_client* client);

/* delete.c */
void	client_delete(s_client* client);
void	client_delete_from_list(void* client);
void	client_kill(s_client* client);

#endif /* !CLIENT_H_ */
