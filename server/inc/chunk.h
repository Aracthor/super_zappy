/*
** chunk.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct 11 23:04:09 2014 
** Last Update Sun Oct 12 00:13:49 2014 
*/

#ifndef CHUNK_H_
# define CHUNK_H_

# include "hoopla.h"

# define CHUNK_SIZE	(16)

typedef struct	chunk
{
  s_hoopla	hooplas[CHUNK_SIZE][CHUNK_SIZE];
}		s_chunk;

/* init.c */
void	chunk_init(s_chunk* chunk);

#endif /* !CHUNK_H_ */
