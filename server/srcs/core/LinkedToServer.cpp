//
// LinkedToServer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 13:17:26 2014 
// Last Update Mon Nov  3 13:30:54 2014 
//

#include "core/LinkedToServer.hh"
#include "core/Server.hh"

LinkedToServer::LinkedToServer()
{
}

LinkedToServer::~LinkedToServer()
{
}


const Server*
LinkedToServer::getServerData() const
{
  return (Server::s_server);
}

Server*
LinkedToServer::getServerData()
{
  return (Server::s_server);
}
