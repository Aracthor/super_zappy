//
// Server.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:42:16 2014 
// Last Update Fri Nov 21 12:22:03 2014 
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
  m_consoleMode(configs.getConsoleMode()),
  m_pid(getpid())
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
Server::startControlPanel()
{
  m_controlPanel = new ControlPanel;

  m_controlPanel->run();

  delete (m_controlPanel);
}

void
Server::wait() const
{
  fd_set	set;

  FD_ZERO(&set);
  FD_SET(STDIN_FILENO, &set);

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

void
Server::stop()
{
  if (m_consoleMode)
    {
    }
  else
    {
      if (close(STDIN_FILENO) == -1)
	throw SyscallException("Error closing stdin : ");
    }
}
