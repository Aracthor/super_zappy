//
// SingletonManager.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 13:43:50 2014 
// Last Update Tue Nov  4 14:28:33 2014 
//

#include "core/SingletonManager.hh"
#include "debug/LogManager.hh"
#include "security/CheatChecker.hh"

SingletonManager::SingletonManager()
{
  LogManagerSingleton::create();
  CheatCheckerSingleton::create();
}

SingletonManager::~SingletonManager()
{
  CheatCheckerSingleton::destroy();
  LogManagerSingleton::destroy();
}
