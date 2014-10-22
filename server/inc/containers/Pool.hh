//
// Pool.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 13 17:23:02 2014 
// Last Update Mon Oct 20 14:58:47 2014 
//

#ifndef POOL_HH_
# define POOL_HH_

# define FOREACH_IN_POOL(i)		for (i = 0; i < m_size; ++i)
# define FOREACH_OF_POOL(pool, i)	for (i = 0; i < (pool).getSize(); ++i)

template <typename T>
class		Pool
{
private:
  T*		m_data;
  unsigned int	m_size;
  unsigned int	m_maxSize;

public:
  Pool(unsigned int maxSize);
  ~Pool();

private:
  void	tryToPush() const;

public:
  void	pushFront(const T& elem);
  void	pushBack(const T& elem);

public:
  void	popElem(const T* elem);

public:
  inline unsigned int	getSize() const;
  inline unsigned int	getMaxSize() const;

public:
  inline const T&	operator[](unsigned int index) const;
  inline T&		operator[](unsigned int index);
};

#include "Pool.hpp"

#endif // !POOL_HH_
