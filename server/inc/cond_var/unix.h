/*
** unix.h<3> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 04:16:11 2014 
** Last Update Sun Oct  5 04:20:48 2014 
*/

#ifndef COND_VAR_UNIX_H_
# define COND_VAR_UNIX_H_

# include <pthread.h>

# include "mutex.h"

typedef struct		cond_var
{
  pthread_cond_t	pthread_cond_var;
  s_mutex		mutex;
}			s_cond_var;

#endif /* !COND_VAR_UNIX_H_ */
