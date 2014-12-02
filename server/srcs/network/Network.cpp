//
// Network.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:55:13 2014 
// Last Update Fri Nov 21 10:43:12 2014 
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
  if (disconnected == false)
    {
      LogManagerSingleton::access()->error->print("Kicking client %d.", client->getFd());
      client->send(KICK_MESSAGE LINE_SEPARATOR_STR);
      if (client->getTeam() != NULL)
	this->discalifyTeam(client->getTeam());
    }

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
