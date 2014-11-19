//
// CommandExecuter.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov 17 17:38:43 2014 
// Last Update Tue Nov 18 14:43:09 2014 
//

#include "core/CommandExecuter.hh"
#include "core/Server.hh"
#include "debug/LogManager.hh"

#include <cstring>

CommandExecuter::CommandExecuter()
{
  this->addCommand("start",	&CommandExecuter::startGame);
  this->addCommand("log",	&CommandExecuter::logAction);
  this->addCommand("reset",	&CommandExecuter::resetGame);
}

CommandExecuter::~CommandExecuter()
{
}


void
CommandExecuter::startGame(const char* params __attribute__ ((unused)))
{
  this->getServerData()->startGame();
}

void
CommandExecuter::logAction(const char* params)
{
  const char*	action;
  bool		valid;

  valid = false;
  action = this->getNextToken(params);
  if (action != NULL)
    {
      m_logParameter.executeLogCommand(action, params, this->getNextToken(action));
      valid = true;
    }

  if (valid == false)
    LogManagerSingleton::access()->error->print("Invalid syntax for log command.");
}

void
CommandExecuter::resetGame(const char* params __attribute__ ((unused)))
{
  this->getServerData()->resetGame();
}
