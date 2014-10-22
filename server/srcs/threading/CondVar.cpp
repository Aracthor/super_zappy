//
// CondVar.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 21 11:45:58 2014 
// Last Update Tue Oct 21 11:51:41 2014 
//

#include "exceptions/ThreadingException.hh"
#include "threading/CondVar.hh"

CondVar::CondVar()
{
  int	error;

  error = pthread_cond_init(&m_condvar, NULL);
  if (error)
    throw ThreadingException("Failed to init condvar : ", error);
}

CondVar::~CondVar()
{
  int	error;

  error = pthread_cond_destroy(&m_condvar);
  if (error)
    throw ThreadingException("Failed to destroy condvar : ", error);
}


void
CondVar::signal()
{
  int	error;

  error = pthread_cond_signal(&m_condvar);
  if (error)
    throw ThreadingException("Failed to signal condvar : ", error);
}

void
CondVar::broadcast()
{
  int	error;

  error = pthread_cond_broadcast(&m_condvar);
  if (error)
    throw ThreadingException("Failed to signal condvar : ", error);
}

void
CondVar::wait()
{
  int	error;

  error = pthread_cond_wait(&m_condvar, &m_mutex.m_mutex);
  if (error)
    throw ThreadingException("Failed to wait condvar : ", error);
}
