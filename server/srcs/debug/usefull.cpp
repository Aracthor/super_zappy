//
// usefull.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Dec  4 09:19:15 2014 
// Last Update Thu Dec  4 09:21:23 2014 
//

#include "debug/LogManager.hh"
#include "debug/usefull.hh"

#include <cstdarg>

bool
checkOrPrint(bool test, const char* message, ...)
{
  va_list	list;

  va_start(list, message);
  {
    if (test == false)
      LogManagerSingleton::access()->error->print(message, list);
  }
  va_end(list);

  return (test);
}
