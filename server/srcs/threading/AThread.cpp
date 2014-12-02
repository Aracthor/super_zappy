//
// AThread.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 10:44:50 2014 
// Last Update Thu Nov 20 12:51:00 2014 
//

#include "exceptions/ThreadingException.hh"
#include "threading/AThread.hh"

static void*	action(AThread* thread)
{
  thread->run();

  return (NULL);
}


AThread::AThread() :
  m_active(false)
{
}

AThread::~AThread()
{
  if (m_active)
    this->join();
}

void
AThread::start()
{
  int		error;

  error = pthread_create(&m_thread, NULL,
			 reinterpret_cast<ThreadRoutine>(&action), this);
  if (error)
    throw ThreadingException("Failed to start a new thread : ", error);

  m_active = true;
}

void
AThread::join()
{
  int	error;

  error = pthread_join(m_thread, NULL);
  if (error)
    throw ThreadingException("Failed to join a thread : ", error);
  m_active = false;
}
