//
// ThreadManager.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 13 15:57:32 2014 
// Last Update Sat Nov  8 20:22:38 2014 
//

#include "actions/ExecuterThread.hh"
#include "network/ListenThread.hh"
#include "network/SpeakThread.hh"
#include "threading/ThreadManager.hh"

ThreadManager::ThreadManager()
{
  m_threads[listen]	= new ListenThread;
  m_threads[speak]	= new SpeakThread;
  m_threads[execute]	= new ExecuterThread;
}

ThreadManager::~ThreadManager()
{
  unsigned int	i;

  FOREACH_THREAD(i)
  {
    m_threads[i]->interrupt();
    delete (m_threads[i]);
  }
}


void
ThreadManager::runThreads()
{
  unsigned int	i;

  FOREACH_THREAD(i)
  {
    m_threads[i]->start();
  }
}
