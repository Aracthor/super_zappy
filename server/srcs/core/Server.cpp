//
// Server.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:42:16 2014 
// Last Update Mon Nov 17 17:50:26 2014 
//

#include "core/ControlPanel.hh"
#include "core/Server.hh"
#include "debug/LogManager.hh"

#include <sys/select.h>

Server*
Server::s_server = NULL;


Server::Server(const Configs& configs) :
  SingletonManager(configs.getLogFile()),
  ActionsManager(configs.getSpeed()),
  GameData(configs),
  Map(configs),
  Network(configs.getPort()),
  ThreadManager(),
  m_consoleMode(configs.getConsoleMode())
{
  s_server = this;
  this->setSpawnPoints(*this);

  if (m_consoleMode)
    LogManagerSingleton::access()->setConsoleMode();
}

Server::~Server()
{
  LogManagerSingleton::access()->intern->print("Server ending...");
}


void
Server::startControlPanel() const
{
  ControlPanel	controlPanel;

  controlPanel.run();
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
  LogManagerSingleton::access()->intern->print("Server starting...");
  this->runThreads();
  LogManagerSingleton::access()->intern->print("Server started !");

  if (m_consoleMode)
    this->startControlPanel();
  else
    this->wait();
}
