/*
** delete.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 07:40:23 2014 
** Last Update Sun Oct  5 07:59:58 2014 
*/

#include "client_thread.h"

void	client_thread_delete(s_client_thread* client_thread)
{
  client_thread->loop = false;
  cond_var_signal(&client_thread->cond_var);
  thread_join(&client_thread->thread);
  cond_var_delete(&client_thread->cond_var);
}
