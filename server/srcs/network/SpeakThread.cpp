//
// SpeakThread.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 21 10:59:36 2014 
// Last Update Mon Nov  3 16:48:04 2014 
//

#include "core/Server.hh"
#include "network/SpeakThread.hh"

SpeakThread::SpeakThread() :
  AZappyThread("Speaker")
{
}

SpeakThread::~SpeakThread()
{
}


bool
SpeakThread::speakToClients()
{
  Client*	client;
  unsigned int	i;
  bool		needToSpeakMore;

  needToSpeakMore = false;

  FOREACH_OF_POOL(m_server->getClients(), i)
    {
      client = &m_server->getClients()[i];
      if (client->wantToSpeak())
	{
	  if (client->send() == false)
	    {
	      m_server->getClients().popElem(client);
	      --i;
	    }
	}
      if (needToSpeakMore == false)
	needToSpeakMore = client->wantToSpeak();
    }

  return (needToSpeakMore);
}

bool
SpeakThread::loopCycle()
{
  bool	needToSpeakMore;

  m_server->lockClients();
  {
    needToSpeakMore = this->speakToClients();
  }
  m_server->unlockClients();

  if (needToSpeakMore == false)
    m_server->getSpeakRing().wait();

  return (true);
}


void
SpeakThread::interrupt()
{
  AZappyThread::interrupt();
  m_server->getSpeakRing().signal();
}
