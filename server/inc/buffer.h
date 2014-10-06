/*
** buffer.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 06:01:44 2014 
** Last Update Sun Oct  5 14:10:49 2014 
*/

#ifndef BUFFER_H_
# define BUFFER_H_

# define BUFFER_SIZE	(0x1000)

typedef struct	buffer
{
  char		data[BUFFER_SIZE];
  unsigned int  full;
}		s_buffer;

/* edit.c */
void	buffer_add(s_buffer* buffer, const char* message);
void	buffer_sub(s_buffer* buffer, unsigned int size);

#endif /* !BUFFER_H_ */
