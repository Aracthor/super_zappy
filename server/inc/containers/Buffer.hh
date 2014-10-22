//
// Buffer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:33:16 2014 
// Last Update Wed Oct 22 10:37:25 2014 
//

#ifndef BUFFER_HH_
# define BUFFER_HH_

template <unsigned int SIZE>
class		Buffer
{
private:
  char		m_data[SIZE];
  unsigned int	m_size;

public:
  Buffer();
  Buffer(const char* data);
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
};

# include "Buffer.hpp"

#endif // !BUFFER_HH_
