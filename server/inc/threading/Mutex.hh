//
// Mutex.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 10:32:15 2014 
// Last Update Tue Oct 21 11:45:24 2014 
//

#ifndef MUTEX_HH_
# define MUTEX_HH_

# include <pthread.h>

class			CondVar;

class			Mutex
{
private:
  pthread_mutex_t	m_mutex;

public:
  Mutex();
  ~Mutex();

public:
  void		lock();
  void		unlock();
  inline bool	trylock();

private:
  friend class	CondVar;
};

#include "Mutex.hpp"

#endif // !MUTEX_HH_
