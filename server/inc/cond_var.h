/*
** cond_var.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 04:11:56 2014 
** Last Update Sun Oct  5 04:18:16 2014 
*/

#ifndef COND_VAR_H_
# define COND_VAR_H_

# include "system.h"

# if (SYSTEM == WINDOWS)
#  include "cond_var/windows.h"
# elif (SYSTEM == OSX)
#  include "cond_var/osx.h"
# elif (SYSTEM == UNIX)
#  include "cond_var/unix.h"
# endif /* (SYSTEM == WINDOWS) */

/* init.c */
void    cond_var_init(s_cond_var* cond_var);

/* delete.c */
void    cond_var_delete(s_cond_var* cond_var);

/* signal.c */
void	cond_var_signal(s_cond_var* cond_var);

/* wait.c */
void	cond_var_wait(s_cond_var* cond_var);

#endif /* !COND_VAR_H_ */
