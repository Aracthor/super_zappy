/*
** allocs.h<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 01:42:43 2014 
** Last Update Thu Oct  9 18:27:27 2014 
*/

#ifndef EXCEPTION_ALLOCS_H_
# define EXCEPTION_ALLOCS_H_

# include <stdlib.h>

# include "exception.h"

# define MALLOC(ptr, size)	{					\
    if ((ptr = malloc(size)) == NULL)					\
      throw (exception_bad_alloc);					\
  }

# define REALLOC(ptr, size)	{					\
    if ((ptr = realloc(ptr, (size))) == NULL)				\
      throw (exception_bad_alloc);					\
  }

# define FREE(ptr)	free(ptr)

/* allocs.c */
int	exception_bad_alloc_handling(unsigned short arg);

#endif /* !EXCEPTION_ALLOCS_H_ */
