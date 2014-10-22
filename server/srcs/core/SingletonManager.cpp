//
// SingletonManager.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 13:43:50 2014 
// Last Update Mon Oct 20 13:45:27 2014 
//

#include "core/SingletonManager.hh"
#include "debug/LogManager.hh"

SingletonManager::SingletonManager()
{
  LogManagerSingleton::create();
}

SingletonManager::~SingletonManager()
{
  LogManagerSingleton::destroy();
}
