//
// Network.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:55:13 2014 
// Last Update Wed Nov  5 13:29:34 2014 
//

#include "debug/LogManager.hh"
#include "network/Network.hh"
#include "network/Protocol.hh"

Network::Network(unsigned int port) :
  m_socket(),
  m_clients(MAX_LISTEN_CLIENTS),
  m_clientsMutex()
{
  m_socket.createSocket();
  m_socket.bind(port);
  m_socket.listen(MAX_LISTEN_CLIENTS);
}

Network::~Network()
{
}


void
Network::kickClient(Client* client, bool disconnected)
{
  if (disconnected == false)
    {
      LogManagerSingleton::access()->error.print("Kicking client %d.",
						 client->getFd());
      client->send(KICK_MESSAGE "\n");
    }
  if (client->getTeam() != NULL)
    client->getTeam()->discalify();

  m_clients.popElem(client);
}
