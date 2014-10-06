/*
** output.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 23:54:56 2014 
** Last Update Sun Oct  5 02:22:09 2014 
*/

#ifndef OUTPUT_H_
# define OUTPUT_H_

# include "debug.h"

# define ERROR_OUTPUT				"\033[00;31m"
# define NORMAL_OUTPUT				"\033[0m"

/* Constant outputs */
# define SERVER_INTERN_ACTION_OUTPUT		"\033[01;36m"
# define CONNECTION_OUTPUT			"\033[01;33m"

/* Debug outputs */
# define RECEIVE_GRAPHICAL_PACKET_OUTPUT	"\033[01;35m"
# define SEND_GRAPHICAL_PACKET_OUTPUT		"\033[00;35m"
# define RECEIVE_IA_PACKET_OUTPUT		"\033[01;32m"
# define SEND_IA_PACKET_OUTPUT			"\033[00;32m"

# define BUFFER_OUTPUT_SIZE	(0x1000)

void	error_message(const char* message, ...);
void	server_intern_action_message(const char* message, ...);
void	connection_message(const char* message, ...);

void	receive_graphical_packet_message(int id, const char* packet);
void    send_graphical_packet_message(int id, const char* packet);
void	receive_ia_packet_message(int id, const char* packet);
void    send_ia_packet_message(int id, const char* packet);

# define RECEIVE_GRAPHICAL_PACKET_MESSAGE(id, packet)	{	\
    if (_PRINT_GRAPHICAL_PACKETS)				\
      receive_graphical_packet_message(id, packet);		\
  }
# define SEND_GRAPHICAL_PACKET_MESSAGE(id, packet)	{	\
    if (_PRINT_GRAPHICAL_PACKETS)				\
      send_graphical_packet_message(id, packet);		\
  }

# define RECEIVE_IA_PACKET_MESSAGE(id, packet)	{	\
    if (_PRINT_IA_PACKETS)				\
      receive_ia_packet_message(id, packet);		\
  }
# define SEND_IA_PACKET_MESSAGE(id, packet)	{	\
    if (_PRINT_IA_PACKETS)				\
      send_ia_packet_message(id, packet);		\
  }

#endif /* !OUTPUT_H_ */
