/*
** keywords.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 01:34:48 2014 
** Last Update Sun Oct  5 01:36:19 2014 
*/

#ifndef EXCEPTION_KEYWORDS_H_
# define EXCEPTION_KEYWORDS_H_

# include <setjmp.h>

# define try(exception)		if ((exception = setjmp(s_g_env)) == 0)
# define catch(exception)	else
# define throw(exception)	longjmp(s_g_env, exception)

jmp_buf	s_g_env;

#endif /* !EXCEPTION_KEYWORDS_H_ */
