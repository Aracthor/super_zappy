/*
** mutex.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 03:07:25 2014 
** Last Update Sun Oct  5 05:11:45 2014 
*/

#ifndef MUTEX_H_
# define MUTEX_H_

# include "boolean.h"
# include "system.h"

# if (SYSTEM == WINDOWS)
#  include "mutex/windows.h"
# elif (SYSTEM == OSX)
#  include "mutex/osx.h"
# elif (SYSTEM == UNIX)
#  include "mutex/unix.h"
# endif /* (SYSTEM == WINDOWS) */

/* init.c */
void	mutex_init(s_mutex* mutex);

/* delete.c */
void	mutex_delete(s_mutex* mutex);

/* lock.c */
void	mutex_lock(s_mutex* mutex);

/* trylock.c */
bool	mutex_trylock(s_mutex* mutex);

/* unlock.c */
void	mutex_unlock(s_mutex* mutex);

#endif /* !MUTEX_H_ */
