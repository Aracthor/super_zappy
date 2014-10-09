/*
** containers.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Wed Oct  8 10:59:37 2014 
** Last Update Wed Oct  8 11:14:52 2014 
*/

#ifndef EXCEPTION_CONTAINERS_H_
# define EXCEPTION_CONTAINERS_H_

typedef enum	exception_container
{
  exception_container_full,
  exception_container_empty,
  exceptions_container_number
}		e_exception_container;

/* containers.c */
int	exception_container_handling(unsigned short arg);

#endif /* !EXCEPTION_CONTAINERS_H_ */
