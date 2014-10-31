//
// DisposableQueue.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 28 15:01:33 2014 
// Last Update Tue Oct 28 15:12:10 2014 
//

#ifndef DISPOSABLE_QUEUE_HH_
# define DISPOSABLE_QUEUE_HH_

template <typename T>
class		DisposableQueue
{
private:
  T*		m_data;
  unsigned int	m_size;
  unsigned int	m_beginIndex;
  unsigned int	m_endIndex;

public:
  DisposableQueue(unsigned int size);
  ~DisposableQueue();

public:
  inline void		push(const T& elem);
  inline void		pop();
  inline const T&	accessFront() const;
  inline const T&	accessBack() const;
  inline bool		isEmpty() const;

public:
  void	reset();
};

# include "DisposableQueue.hpp"

#endif // !DISPOSABLE_QUEUE_HH_
