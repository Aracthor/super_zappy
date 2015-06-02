//
// SigpipeHandler.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by aracthor
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Feb 24 15:30:17 2015 aracthor
// Last Update Tue Feb 24 15:30:52 2015 aracthor
//

#include <iostream>

#include "abstractions/SigpipeHandler.hh"
#include "core/Server.hh"
#include "debug/LogManager.hh"
#include "exceptions/SignalException.hh"

SigpipeHandler::SigpipeHandler()
{
}

SigpipeHandler::~SigpipeHandler()
{
}


void
SigpipeHandler::onCatch()
{
  LogManagerSingleton::access()->error->print("Fatal server error : Broken pipe :(");
  if (this->getServerData() != NULL && getpid() != this->getServerData()->getServerPid())
    this->getServerData()->stop();
  exit(0x80 + SIGPIPE);
}
