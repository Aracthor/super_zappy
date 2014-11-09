//
// ThreadManager.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 13 15:52:49 2014 
// Last Update Sat Nov  8 20:22:31 2014 
//

#ifndef THREAD_MANAGER_HH_
# define THREAD_MANAGER_HH_

# include "threading/AZappyThread.hh"

# define FOREACH_THREAD(i)	for (i = 0; i < threads_number; ++i)

class		ThreadManager
{
private:
  enum		EThread
  {
    listen,
    speak,
    execute,
    threads_number
  };

private:
  AZappyThread*	m_threads[threads_number];

public:
  ThreadManager();
  virtual ~ThreadManager();

public:
  void	runThreads();
};

#endif // !THREAD_MANAGER_HH_
