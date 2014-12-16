//
// Network.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:55:13 2014 
// Last Update Thu Dec 11 17:48:28 2014 
//

#include "debug/LogManager.hh"
#include "network/Network.hh"
#include "network/Protocol.hh"

#include <cstdarg>
#include <cstdio>

Network::Network(unsigned int port) :
  m_socket(),
  m_clients(MAX_LISTEN_CLIENTS),
  m_clientsMutex()
{
  LogManagerSingleton::access()->intern->print("Network creation...");
  m_socket.createSocket();
  m_socket.bind(port);
  m_socket.listen(MAX_LISTEN_CLIENTS);
}

Network::~Network()
{
  LogManagerSingleton::access()->intern->print("Network destruction...");
}


void
Network::discalifyTeam(Team* team)
{
  team->discalify();
  this->sayToGraphicClients(*team);
}

void
Network::kickClient(Client* client, bool disconnected)
{
  // unsigned int	index;

  if (disconnected == false)
    {
      LogManagerSingleton::access()->error->print("Kicking client %d.", client->getFd());
      client->send(KICK_MESSAGE LINE_SEPARATOR_STR);
      if (client->getTeam() != NULL)
	this->discalifyTeam(client->getTeam());
    }

  // index = m_clients.indexOf(client);
  // while (++index < m_clients.getSize())
  //   if (m_clients[index].isPlayer())
  //     {
  // 	m_clients[index].getTeam()->setClient(&m_clients[index - 1]);
  // 	m_clients[index - 1].giveTeam(m_clients[index].getTeam());
  //     }
  m_clients.popElem(client);
}

void
Network::vsayToGraphicClients(const char* message, ...)
{
  va_list	list;
  char	        buffer[0x100];

  va_start(list, message);
  {
    vsprintf(buffer, message, list);
    this->sayToGraphicClients(buffer);
  }
  va_end(list);
}
