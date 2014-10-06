/*
** thread.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 02:52:39 2014 
** Last Update Sun Oct  5 04:46:27 2014 
*/

#ifndef THREAD_H_
# define THREAD_H_

# include "system.h"

typedef void*	(*t_thread_start)(void* arg);

# if (SYSTEM == WINDOWS)
#  include "thread/windows.h"
# elif (SYSTEM == OSX)
#  include "thread/osx.h"
# elif (SYSTEM == UNIX)
#  include "thread/unix.h"
# endif /* (SYSTEM == WINDOWS) */

/* init.c */
void	thread_init(s_thread* thread, t_thread_start start, void* arg);

/* delete.c */
void	thread_delete(s_thread* thread);

/* join.c */
void*	thread_join(s_thread* thread);

#endif /* !THREAD_H_ */
