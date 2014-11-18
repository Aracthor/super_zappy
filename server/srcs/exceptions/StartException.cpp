//
// StartException.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov 18 10:29:00 2014 
// Last Update Tue Nov 18 10:29:02 2014 
//

#include "exceptions/StartException.hh"

StartException::StartException(const char* name) :
  ZappyException(name)
{
}

StartException::~StartException() throw()
{
}
