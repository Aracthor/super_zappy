//
// SigsegvHandler.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server/code_qui_fait_segfault_valgrind
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 21 09:59:05 2014 
// Last Update Fri Nov 21 12:23:46 2014 
//

#include <iostream>

#include "abstractions/SigsegvHandler.hh"
#include "core/Server.hh"
#include "debug/LogManager.hh"
#include "exceptions/SignalException.hh"

SigsegvHandler::SigsegvHandler()
{
}

SigsegvHandler::~SigsegvHandler()
{
}


void
SigsegvHandler::onCatch()
{
  LogManagerSingleton::access()->error->print("Fatal server error : Segmentation fault :(");
  if (getpid() != this->getServerData()->getServerPid())
    {
      this->getServerData()->stop();
      exit(0x80 + SIGSEGV);
    }
  else
    throw SignalException(SIGSEGV);
}
