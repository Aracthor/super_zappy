/*
** client_thread.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 07:25:00 2014 
** Last Update Sun Oct  5 14:17:35 2014 
*/

#ifndef CLIENT_THREAD_H_
# define CLIENT_THREAD_H_

# include "boolean.h"
# include "cond_var.h"
# include "thread.h"

typedef struct	client_thread
{
  s_mutex	mutex;
  s_cond_var	cond_var;
  s_thread	thread;
  bool		loop;
}		s_client_thread;

/* init.c */
void	client_thread_init(s_client_thread* client_thread, void* client);

/* loop.c */
void*   client_thread_loop(void* data);

/* delete.c */
void	client_thread_delete(s_client_thread* client_thread);

#endif /* !CLIENT_THREAD_H_ */
