/*
** graphical_thread.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 05:23:42 2014 
** Last Update Sun Oct  5 07:32:17 2014 
*/

#ifndef GRAPHICAL_THREAD_H_
# define GRAPHICAL_THREAD_H_

# include "boolean.h"
# include "client.h"
# include "cond_var.h"
# include "thread.h"

typedef struct	graphical_thread
{
  s_mutex	mutex;
  s_cond_var	cond_var;
  s_thread	thread;
  char		data_to_send[BUFFER_SIZE];
  bool		loop;
}		s_graphical_thread;

/* init.c */
void	graphical_thread_init(s_graphical_thread* graphical_thread, void* server);

/* loop.c */
void	graphical_thread_send_message(s_graphical_thread* graphical_thread, char* message);
void*	graphical_thread_loop(void* data);

/* delete.c */
void	graphical_thread_delete(s_graphical_thread* graphical_thread);

#endif /* !GRAPHICAL_THREAD_H_ */
