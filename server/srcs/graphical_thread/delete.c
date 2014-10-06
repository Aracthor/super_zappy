/*
** delete.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 05:31:15 2014 
** Last Update Sun Oct  5 07:51:11 2014 
*/

#include "graphical_thread.h"

void	graphical_thread_delete(s_graphical_thread* graphical_thread)
{
  graphical_thread->loop = false;
  cond_var_signal(&graphical_thread->cond_var);
  thread_join(&graphical_thread->thread);
  cond_var_delete(&graphical_thread->cond_var);
  mutex_delete(&graphical_thread->mutex);
}
