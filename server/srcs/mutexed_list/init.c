/*
** init.c<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 03:12:24 2014 
** Last Update Sun Oct  5 03:19:09 2014 
*/

#include <stddef.h>

#include "mutexed_list.h"

void	mutexed_list_init(s_mutexed_list* mutexed_list)
{
  mutex_init(&mutexed_list->mutex);
  mutexed_list->data = NULL;
}
