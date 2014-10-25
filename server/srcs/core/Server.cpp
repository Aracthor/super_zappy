//
// Server.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:42:16 2014 
// Last Update Fri Oct 24 09:31:50 2014 
//

#include "core/Server.hh"
#include "debug/LogManager.hh"

#include <unistd.h>

Server*
Server::s_server = NULL;


Server::Server(const Configs& configs) :
  SingletonManager(),
  GameData(configs),
  Map(configs.getMapConfigs()),
  Network(configs.getPort()),
  ThreadManager()
{
  s_server = this;
}

Server::~Server()
{
  LogManagerSingleton::access()->intern.print("Server ending...");
}


void
Server::loop()
{
  char	useless;

  read(0, &useless, 1);
}


void
Server::start()
{
  LogManagerSingleton::access()->intern.print("Server starting...");
  this->runThreads();
  LogManagerSingleton::access()->intern.print("Server started !");
  this->loop();
}
