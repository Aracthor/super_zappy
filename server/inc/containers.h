/*
** containers.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Wed Oct  8 09:51:51 2014 
** Last Update Wed Oct  8 10:43:20 2014 
*/

#ifndef CONTAINERS_H_
# define CONTAINERS_H_

# include <sys/types.h>

# include "boolean.h"

typedef void	(*t_delete_fun)(void* data);
typedef bool	(*t_cond_fun)(void* data, void* ref);

#endif /* !CONTAINERS_H_ */
