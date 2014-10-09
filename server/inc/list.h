/*
** list.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 01:38:19 2014 
** Last Update Wed Oct  8 11:20:30 2014 
*/

#ifndef LIST_H_
# define LIST_H_

# include "containers.h"

typedef struct	list
{
  void*		data;
  struct list*	next;
}		s_list;

/* access.c */
void*	front(const s_list* list);
void*	back(const s_list* list);
bool	is_in_list(const s_list* list, void* data);
void*	find(const s_list* list, void* ref, t_cond_fun fun);
int	count(const s_list* list, void* ref, t_cond_fun fun);

/* conditions.c */
bool	is_elem(void* data, void* ref);

/* delete.c */
void	pop_front(s_list** list, t_delete_fun delete_fun);
void	pop_back(s_list** list, t_delete_fun delete_fun);
void	pop_cond(s_list** list, void* ref,
		 t_cond_fun cond_fun, t_delete_fun delete_fun);
void	list_delete(s_list** list, t_delete_fun delete_fun);

/* edit.c */
void	push_front(s_list** list, void* data, size_t size);
void	push_back(s_list** list, void* data, size_t size);

#endif /* !LIST_H_ */
