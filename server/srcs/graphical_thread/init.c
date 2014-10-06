/*
** init.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 05:25:39 2014 
** Last Update Sun Oct  5 07:58:16 2014 
*/

#include "graphical_thread.h"

void	graphical_thread_init(s_graphical_thread* graphical_thread, void* server)
{
  mutex_init(&graphical_thread->mutex);
  cond_var_init(&graphical_thread->cond_var);
  graphical_thread->loop = true;
  thread_init(&graphical_thread->thread,
	      (t_thread_start)&graphical_thread_loop, server);
}
