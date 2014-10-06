/*
** delete.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 03:14:06 2014 
** Last Update Sun Oct  5 03:17:09 2014 
*/

#include "mutexed_list.h"

void	mutexed_list_delete(s_mutexed_list* mutexed_list, t_delete_fun delete_fun)
{
  mutex_delete(&mutexed_list->mutex);
  list_delete(&mutexed_list->data, delete_fun);
}
