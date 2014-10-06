/*
** init.c<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 07:33:39 2014 
** Last Update Sun Oct  5 08:06:20 2014 
*/

#include "client_thread.h"

void	client_thread_init(s_client_thread* client_thread, void* client)
{
  mutex_init(&client_thread->mutex);
  cond_var_init(&client_thread->cond_var);
  client_thread->loop = true;
  thread_init(&client_thread->thread, (t_thread_start)&client_thread_loop, client);
}
