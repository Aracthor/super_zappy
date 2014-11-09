//
// Server.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:42:16 2014 
// Last Update Sat Nov  8 20:43:05 2014 
//

#include "core/Server.hh"
#include "debug/LogManager.hh"

#include <sys/select.h>

Server*
Server::s_server = NULL;


Server::Server(const Configs& configs) :
  SingletonManager(),
  ActionsManager(configs.getSpeed()),
  GameData(configs),
  Map(configs),
  Network(configs.getPort()),
  ThreadManager()
{
  s_server = this;
  this->setSpawnPoints(*this);

  this->startGame(); // TEST ONLY
}

Server::~Server()
{
  LogManagerSingleton::access()->intern.print("Server ending...");
}


void
Server::wait() const
{
  fd_set	set;

  FD_ZERO(&set);
  FD_SET(0, &set);

  select(1, &set, NULL, NULL, NULL);
}


void
Server::start()
{
  LogManagerSingleton::access()->intern.print("Server starting...");
  this->runThreads();
  LogManagerSingleton::access()->intern.print("Server started !");

  this->wait();
}
