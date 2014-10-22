//
// Mutex.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 10:34:21 2014 
// Last Update Sun Oct 12 10:39:54 2014 
//

#include "exceptions/ThreadingException.hh"
#include "threading/Mutex.hh"

Mutex::Mutex()
{
  pthread_mutex_init(&m_mutex, NULL);
}

Mutex::~Mutex()
{
  int	error;

  error = pthread_mutex_destroy(&m_mutex);
  if (error)
    throw ThreadingException("Failed to destroy mutex : ", error);
}


void
Mutex::lock()
{
  int	error;

  error = pthread_mutex_lock(&m_mutex);
  if (error)
    throw ThreadingException("Failed to lock mutex : ", error);
}

void
Mutex::unlock()
{
  int	error;

  error = pthread_mutex_unlock(&m_mutex);
  if (error)
    throw ThreadingException("Failed to unlock mutex : ", error);
}
