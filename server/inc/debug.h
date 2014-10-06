/*
** debug.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 00:14:50 2014 
** Last Update Sun Oct  5 00:27:12 2014 
*/

#ifndef DEBUG_H_
# define DEBUG_H_

# define DEBUG_ENABLED	(1)

# define IS_NOT_BOOLEAN(maccro)	(maccro != 0 && maccro != 1)

# ifndef _PRINT_GRAPHICAL_PACKETS
#  define _PRINT_GRAPHICAL_PACKETS	(DEBUG_ENABLED)
# elif IS_NOT_BOOLEAN(_PRINT_GRAPHICAL_PACKETS)
#  error "_PRINT_GRAPHICAL_PACKETS have to be a boolean."
# endif /* !_PRINT_GRAPHICAL_PACKETS */

# ifndef _PRINT_IA_PACKETS
#  define _PRINT_IA_PACKETS	(DEBUG_ENABLED)
# elif IS_NOT_BOOLEAN(_PRINT_GRAPHICAL_PACKETS)
#  error "_PRINT_IA_PACKETS have to be a boolean."
# endif /* !_PRINT_IA_PACKETS */

#endif /* !DEBUG_H_ */