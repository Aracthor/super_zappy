/*
** edit.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 01:43:59 2014 
** Last Update Sun Oct  5 01:50:06 2014 
*/

#include <string.h>

#include "exception.h"
#include "list.h"

static s_list*	prepare_elem(void* data, size_t size)
{
  s_list*	elem;

  MALLOC(elem, sizeof(s_list));
  MALLOC(elem->data, size);
  memcpy(elem->data, data, size);

  return (elem);
}

void		push_front(s_list** list, void* data, size_t size)
{
  s_list*	elem;

  elem = prepare_elem(data, size);
  elem->next = *list;
  *list = elem;
}

void		push_back(s_list** list, void* data, size_t size)
{
  s_list*	elem;
  s_list*	copy;

  elem = prepare_elem(data, size);
  elem->next = NULL;

  if (*list == NULL)
    *list = elem;
  else
    {
      copy = *list;
      while (copy->next != NULL)
	copy = copy->next;
      copy->next = elem;
    }
}
