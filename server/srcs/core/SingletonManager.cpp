//
// SingletonManager.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 13:43:50 2014 
// Last Update Fri Dec  5 14:28:40 2014 
//

#include "core/SingletonManager.hh"
#include "debug/LogManager.hh"
#include "map/NamesRegister.hh"
#include "security/CheatChecker.hh"

SingletonManager::SingletonManager(const char* file)
{
  LogManagerSingleton::create(file);
  CheatCheckerSingleton::create();
  NamesRegisterSingleton::create();
}

SingletonManager::~SingletonManager()
{
  NamesRegisterSingleton::destroy();
  CheatCheckerSingleton::destroy();
  LogManagerSingleton::destroy();
}
