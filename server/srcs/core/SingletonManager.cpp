//
// SingletonManager.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 13:43:50 2014 
// Last Update Mon Nov 17 13:28:19 2014 
//

#include "core/SingletonManager.hh"
#include "debug/LogManager.hh"
#include "security/CheatChecker.hh"

SingletonManager::SingletonManager(const char* file)
{
  LogManagerSingleton::create(file);
  CheatCheckerSingleton::create();
}

SingletonManager::~SingletonManager()
{
  CheatCheckerSingleton::destroy();
  LogManagerSingleton::destroy();
}
