/*
** system.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 03:21:02 2014 
** Last Update Sun Oct  5 03:22:16 2014 
*/

#ifndef SYSTEM_H_
# define SYSTEM_H_

# define WINDOWS	(1)
# define OSX		(2)
# define UNIX		(3)

# if defined(_WIN32) || defined(_WIN64)
#  define SYSTEM	(WINDOWS)
# elif defined(__APPLE__) || defined(__MACH__)
#  define SYSTEM	(OSX)
# elif defined(__linux__) || defined(__FreeBSD__)
#  define SYSTEM	(UNIX)
# else
#  error "System not recognized"
# endif /* defined(_WIN32) || defined(_WIN64) */

#endif /* !SYSTEM_H_ */
