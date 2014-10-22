//
// AThread.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 10:42:16 2014 
// Last Update Tue Oct 21 10:27:06 2014 
//

#ifndef THREAD_HH_
# define THREAD_HH_

# include <pthread.h>

class		AThread
{
private:
  typedef void*	(*ThreadRoutine)(void* data);

private:
  pthread_t	m_thread;
  bool		m_active;

public:
  AThread();
  virtual ~AThread();

public:
  virtual void	start();
  void		join();

public:
  virtual void  run() = 0;
  virtual void	interrupt() = 0;
};

#endif // !THREAD_HH_
