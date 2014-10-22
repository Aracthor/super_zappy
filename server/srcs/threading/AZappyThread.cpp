//
// AZappyThread.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 13 15:21:08 2014 
// Last Update Tue Oct 21 10:27:24 2014 
//

#include <exception>

#include "core/Server.hh"
#include "debug/LogManager.hh"
#include "threading/AZappyThread.hh"

AZappyThread::AZappyThread(const char* name) :
  m_name(name),
  m_loop(true)
{
}

AZappyThread::~AZappyThread()
{
}


void
AZappyThread::start()
{
  m_server = Server::accessServer();
  AThread::start();
}

void
AZappyThread::run()
{
  bool	loop;

  LogManagerSingleton::access()->threading.print("Thread %s started !", m_name);

  try
    {
      while (m_loop)
	{
	  loop = this->loopCycle();
	  if (loop == false || m_loop == false)
	    m_loop = false;
	}
    }

  catch (const std::exception& exception)
    {
      LogManagerSingleton::access()->error.print("Fatal error in thread %s : %s",
						 m_name, exception.what());
    }

  LogManagerSingleton::access()->threading.print("Thread %s ended !", m_name);

}

void
AZappyThread::interrupt()
{
  m_loop = false;
}
