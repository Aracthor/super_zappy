/*
** keywords.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 01:34:48 2014 
** Last Update Wed Oct  8 10:48:04 2014 
*/

#ifndef EXCEPTION_KEYWORDS_H_
# define EXCEPTION_KEYWORDS_H_

# include <setjmp.h>

# define try(exception)		if ((exception = setjmp(g_env)) == 0)
# define catch(exception)	else
# define throw(exception)	longjmp(g_env, exception)

jmp_buf	g_env;

#endif /* !EXCEPTION_KEYWORDS_H_ */
