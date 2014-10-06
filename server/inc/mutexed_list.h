/*
** mutexed_list.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 03:10:19 2014 
** Last Update Sun Oct  5 03:19:45 2014 
*/

#ifndef MUTEXED_LIST_H_
# define MUTEXED_LIST_H_

# include "list.h"
# include "mutex.h"

typedef struct	mutexed_list
{
  s_mutex	mutex;
  s_list*	data;
}		s_mutexed_list;

/* init.c */
void	mutexed_list_init(s_mutexed_list* mutexed_list);

/* delete.c */
void	mutexed_list_delete(s_mutexed_list* mutexed_list, t_delete_fun delete_fun);

#endif /* !MUTEXED_LIST_H_ */
