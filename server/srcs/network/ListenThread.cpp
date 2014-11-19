//
// ListenThread.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 13 16:40:27 2014 
// Last Update Tue Nov 18 12:02:22 2014 
//

#include "abstractions/maths.hh"
#include "core/Server.hh"
#include "exceptions/SyscallException.hh"
#include "network/ListenThread.hh"
#include "network/Protocol.hh"

#include <cstring>
#include <sys/select.h>
#include <unistd.h>

ListenThread::ListenThread() :
  AZappyThread("Listener")
{
}

ListenThread::~ListenThread()
{
}


void
ListenThread::getNewClient()
{
  Client	client(m_server->getSocket());

  m_server->getClients().pushBack(client);
}

bool
ListenThread::readClientLine(Client* client, char* line)
{
  bool	correct;

  if (client->isGraphic())
    correct = m_graphicListener.listenFromClient(client, line);
  else if (client->isPlayer())
    correct = m_iaListener.listenFromClient(client, line);
  else
    correct = m_authentificationListener.listenFromClient(client, line);

  return (correct);
}

bool
ListenThread::tryToReadLines(Client* client)
{
  unsigned int	size;
  char*		line;
  char*		pos;
  bool		correct;

  line = client->getInput().getData();
  correct = true;
  while (correct && (pos = strchr(line, LINE_SEPARATOR)) != NULL)
    {
      *pos = '\0';
      size = strlen(line);
      correct = this->readClientLine(client, line);
      client->getInput().popFront(size + 1);
    }

  if (correct == false)
    m_server->kickClient(client, false);

  return (correct);
}

bool
ListenThread::listenClient(Client* client)
{
  bool	connected;

  connected = client->recv();
  if (connected == false)
    m_server->kickClient(client, true);
  else
    connected = this->tryToReadLines(client);

  return (connected);
}


int
ListenThread::listClients(fd_set* clients) const
{
  const Client*	client;
  unsigned int	i;
  int		maxfd;

  maxfd = m_server->getFd();
  FD_ZERO(clients);
  FD_SET(m_server->getListenPipe().getInput(), clients);
  FD_SET(m_server->getFd(), clients);

  FOREACH_OF_POOL(m_server->getClients(), i)
    {
      client = &m_server->getClients()[i];
      maxfd = MAX(maxfd, client->getFd());
      FD_SET(client->getFd(), clients);
    }

  return (maxfd);
}

void
ListenThread::listenClients(fd_set* clients)
{
  Client*	client;
  unsigned int	i;

  if (FD_ISSET(m_server->getFd(), clients))
    this->getNewClient();

  FOREACH_OF_POOL(m_server->getClients(), i)
    {
      client = &m_server->getClients()[i];
      if (FD_ISSET(client->getFd(), clients))
	if (this->listenClient(client) == false)
	  --i;
    }
}


bool
ListenThread::loopCycle()
{
  fd_set	clientsToListen;
  int		maxfd;

  m_server->lockClients();
  {
    maxfd = this->listClients(&clientsToListen);
  }
  m_server->unlockClients();

  if (select(maxfd + 1, &clientsToListen, NULL, NULL, NULL) == -1)
    throw SyscallException("Select failed in the listen thread : ");

  m_server->lockClients();
  m_server->lockActions();
  {
    this->listenClients(&clientsToListen);
  }
  m_server->unlockActions();
  m_server->unlockClients();

  m_server->getSpeakRing().signal();

  return (!FD_ISSET(m_server->getListenPipe().getInput(), &clientsToListen));
}

void
ListenThread::interrupt()
{
  AZappyThread::interrupt();
  m_server->getListenPipe() << "YOLO";
}
