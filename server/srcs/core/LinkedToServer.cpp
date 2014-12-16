//
// LinkedToServer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 13:17:26 2014 
// Last Update Mon Dec 15 13:25:14 2014 
//

#include "core/LinkedToServer.hh"
#include "core/Server.hh"

LinkedToServer::LinkedToServer() :
  m_server(NULL)
{
}

LinkedToServer::~LinkedToServer()
{
}


const Server*
LinkedToServer::getServerData() const
{
  if (m_server == NULL)
    m_server = Server::s_server;
  return (m_server);
}

Server*
LinkedToServer::getServerData()
{
  if (m_server == NULL)
    m_server = Server::s_server;
  return (m_server);
}
