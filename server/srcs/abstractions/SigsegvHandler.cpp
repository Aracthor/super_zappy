//
// SigsegvHandler.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server/code_qui_fait_segfault_valgrind
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 21 09:59:05 2014 
// Last Update Tue Feb 24 15:30:07 2015 aracthor
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
  if (this->getServerData() != NULL && getpid() != this->getServerData()->getServerPid())
    this->getServerData()->stop();
  exit(0x80 + SIGSEGV);
}
