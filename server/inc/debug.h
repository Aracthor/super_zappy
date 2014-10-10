/*
** debug.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 00:14:50 2014 
** Last Update Thu Oct  9 16:45:46 2014 
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
#  define _PRINT_IA_PACKETS		(DEBUG_ENABLED)
# elif IS_NOT_BOOLEAN(_PRINT_GRAPHICAL_PACKETS)
#  error "_PRINT_IA_PACKETS have to be a boolean."
# endif /* !_PRINT_IA_PACKETS */

# ifndef _PRINT_UNKNOWN_PACKETS
#  define _PRINT_UNKNOWN_PACKETS	(DEBUG_ENABLED)
# elif IS_NOT_BOOLEAN(_PRINT_UNKNOWN_PACKETS)
#  error "_PRINT_UNKNOWN_PACKETS have to be a boolean."
# endif /* !_PRINT_UNKNOWN_PACKETS */

# ifndef _SECURE_CONTAINERS
#  define _SECURE_CONTAINERS	(DEBUG_ENABLED)
# elif IS_NOT_BOOLEAN(_SECURE_CONTAINERS)
#  error "_SECURE_CONTAINERS have to be a boolean."
# endif /* !_SECURE_CONTAINERS */


# define IS_AT_LEAST_ONE_PACKET_DEBUG	(_PRINT_IA_PACKETS || _PRINT_GRAPHICAL_PACKETS || _PRINT_UNKNOWN_PACKETS)


#endif /* !DEBUG_H_ */
