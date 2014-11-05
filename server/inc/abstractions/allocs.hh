//
// allocs.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:50:41 2014 
// Last Update Mon Nov  3 16:12:48 2014 
//

#ifndef ALLOCS_HH_
# define ALLOCS_HH_

# include <cstdlib>
# include <new>

# define MALLOC(ptr, size, type)	{				\
    if ((ptr = (type*)malloc(sizeof(type) * (size))) == NULL)		\
      throw std::bad_alloc();						\
  }

# define REALLOC(ptr, size, type)	{				\
    if ((ptr = (type*)realloc((ptr), sizeof(type) * (size))) == NULL)	\
      throw std::bad_alloc();						\
  }

#endif // !ALLOCS_HH_
