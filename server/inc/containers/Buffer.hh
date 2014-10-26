//
// Buffer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:33:16 2014 
// Last Update Sat Oct 25 19:25:04 2014 
//

#ifndef BUFFER_HH_
# define BUFFER_HH_

# if defined(_BUFFER_STACK_MODE) && defined(_BUFFER_ALLOC_MODE)
#  error "You cannot define _BUFFER_STACK_MODE and _BUFFER_ALLOC_MODE."
# elif !defined(_BUFFER_STACK_MODE) && !defined(_BUFFER_ALLOC_MODE)
#  define _BUFFER_STACK_MODE
# endif // !defined(_BUFFER_STACK_MODE) && !defined(_BUFFER_ALLOC_MODE)

# ifdef _BUFFER_STACK_MODE
#  define DEFINE_DATA(SIZE)	char	m_data[SIZE]
# elif _BUFFER_ALLOC_MODE
#  define DEFINE_DATA(SIZE)	char*	m_data
# endif // _BUFFER_STACK_MODE

template <unsigned int SIZE>
class		Buffer
{
private:
  DEFINE_DATA(SIZE);
  unsigned int	m_size;
  mutable bool	m_copy;

public:
  Buffer();
  Buffer(const char* data);
  Buffer(const Buffer<SIZE>& copy);
  ~Buffer();

public:
  void		popFront(unsigned int size);
  void		pushBack(const char data);
  void		pushBack(const char* data, unsigned int size);
  inline void	pushBack(const char* data);

public:
  inline void	addToSize(unsigned int size);

public:
  inline bool		isEmpty() const;
  inline unsigned int	getSize() const;
  inline const char*	getData() const;
  inline char*		getData();
  inline char*		getEnd();

public:
  Buffer<SIZE>&		operator=(const Buffer<SIZE>& copy);
};

# ifdef _BUFFER_STACK_MODE
#  include "BufferStack.hpp"
# elif _BUFFER_ALLOC_MODE
#  include "BufferAlloc.hpp"
# endif // _BUFFER_STACK_MODE

#endif // !BUFFER_HH_
