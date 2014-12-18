//
// CommandExecuter.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov 17 17:38:43 2014 
// Last Update Tue Dec 16 11:59:49 2014 
//

#include "core/CommandExecuter.hh"
#include "core/Server.hh"
#include "debug/LogManager.hh"

#include <cstdlib>
#include <cstring>

CommandExecuter::CommandExecuter()
{
  this->addCommand("start",	&CommandExecuter::startGame);
  this->addCommand("stop",	&CommandExecuter::stopGame);
  this->addCommand("log",	&CommandExecuter::logAction);
  this->addCommand("reset",	&CommandExecuter::resetGame);
  this->addCommand("rebuild",	&CommandExecuter::rebuildMap);
  this->addCommand("speed",	&CommandExecuter::changeSpeed);
}

CommandExecuter::~CommandExecuter()
{
}


bool
CommandExecuter::resize(Map* map, const char* widthStr, const char* heightStr)
{
  unsigned int	width;
  unsigned int	height;
  bool		valid;

  width = atoi(widthStr);
  height = atoi(heightStr);
  valid = (width >= MAP_SIZE_MIN  && width <= MAP_SIZE_MAX &&
	   height >= MAP_SIZE_MIN  && height <= MAP_SIZE_MAX);
  if (valid)
    map->resize(width, height);
  else
    LogManagerSingleton::access()->error->print("Bad map size.");

  return (valid);
}


void
CommandExecuter::startGame(const char* params __attribute__ ((unused)))
{
  this->getServerData()->startGame();
}

void
CommandExecuter::stopGame(const char* params __attribute__ ((unused)))
{
  this->getServerData()->pauseGame();
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

void
CommandExecuter::rebuildMap(const char* params)
{
  Map*		map;
  const char*	ptr;
  bool		valid;

  if (this->getServerData()->isStarted())
    LogManagerSingleton::access()->error->print("Cannot do that when the game is started.");
  else if (this->getServerData()->isAnyPlayer())
    LogManagerSingleton::access()->error->print("Cannot do that when there is any player already present.");
  else
    {
      map = this->getServerData();
      valid = true;

      if (*params != '\0' &&
	  (ptr = this->getNextToken(params)) != NULL)
	valid = this->resize(map, params, ptr);

      if (valid)
	{
	  map->terraform();
	  this->getServerData()->setSpawnPoints(*map);
	  this->getServerData()->vsayToGraphicClients("MAP %d %d\n", map->getWidth(), map->getHeight());
	}
    }
}

void
CommandExecuter::changeSpeed(const char* params)
{
  unsigned int	newSpeed;

  newSpeed = atoi(params);
  if (newSpeed < SPEED_MIN || newSpeed > SPEED_MAX)
    LogManagerSingleton::access()->error->print("Invalid speed.");
  else
    this->getServerData()->changeSpeed(newSpeed);
    
}


void
CommandExecuter::executeCommand(const char* command)
{
  AExecuter::executeCommand(command);
  this->getServerData()->getSpeakRing().signal();
}

void
CommandExecuter::executeCommand(const char* name, const char* param)
{
  AExecuter::executeCommand(name, param);
  this->getServerData()->getSpeakRing().signal();
}
