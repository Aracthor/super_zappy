/*
** access.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 01:39:51 2014 
** Last Update Sun Oct  5 01:41:29 2014 
*/

#include <stddef.h>

#include "list.h"

void*	front(const s_list *list)
{
  void*	data;

  data = NULL;
  if (list != NULL)
    data = list->data;
  return (data);
}

void*	back(const s_list *list)
{
  void*	data;

  data = NULL;
  if (list != NULL)
    {
      while (list->next != NULL)
	list = list->next;
      data = list->data;
    }
  return (data);
}

bool	is_in_list(const s_list *list, void *data)
{
  bool	found;

  found = false;
  while (found == false && list != NULL)
    {
      if (list->data == data)
	found = true;
      list = list->next;
    }
  return (found);
}

void*	find(const s_list *list, void *ref, t_cond_fun fun)
{
  void*	data;

  data = NULL;
  while (data == NULL && list != NULL)
    {
      if (fun(list->data, ref))
	data = list->data;
      list = list->next;
    }
  return (data);
}

int	count(const s_list *list, void *ref, t_cond_fun fun)
{
  int	counted;

  counted = 0;
  while (list != NULL)
    {
      if (fun(list->data, ref))
	++counted;
      list = list->next;
    }
  return (counted);
}
