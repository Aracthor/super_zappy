//
// Network.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:55:13 2014 
// Last Update Tue Oct 21 13:56:43 2014 
//

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
    client->send(KICK_MESSAGE "\n");
  m_clients.popElem(client);
}
