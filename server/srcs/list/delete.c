/*
** delete.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 01:41:34 2014 
** Last Update Sun Oct  5 02:28:14 2014 
*/

#include "exception.h"
#include "list.h"

static void	delete_elem(s_list* elem, t_delete_fun delete_fun)
{
  if (delete_fun != NULL)
    delete_fun(elem->data);
  FREE(elem->data);
  FREE(elem);
}

void		pop_front(s_list** list, t_delete_fun delete_fun)
{
  s_list*	elem;

  elem = *list;
  *list = (*list)->next;
  delete_elem(elem, delete_fun);
}

void		pop_back(s_list** list, t_delete_fun delete_fun)
{
  s_list*	copy;
  s_list*	elem;

  copy = *list;
  if (copy->next == NULL)
    pop_front(list, delete_fun);
  else
    {
      while (copy->next->next != NULL)
	copy = copy->next;
      elem = copy->next;
      copy->next = NULL;
      delete_elem(elem, delete_fun);
    }
}

void		pop_cond(s_list** list, void* ref,
			 t_cond_fun cond_fun, t_delete_fun delete_fun)
{
  s_list*	elem;
  s_list*	copy;

  if (cond_fun((*list)->data, ref))
    pop_front(list, delete_fun);
  else
    {
      copy = *list;
      while (copy->next != NULL && cond_fun(copy->next->data, ref) == false)
	copy = copy->next;
      if (copy->next != NULL)
	{
	  elem = copy->next;
	  copy->next = copy->next->next;
	  delete_elem(elem, delete_fun);
	}
    }
}

void		list_delete(s_list** list, t_delete_fun delete_fun)
{
  s_list*	elem;

  while (*list != NULL)
    {
      elem = *list;
      *list = (*list)->next;
      delete_elem(elem, delete_fun);
    }
}
