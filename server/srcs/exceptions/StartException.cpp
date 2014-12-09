//
// StartException.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov 18 10:29:00 2014 
// Last Update Fri Dec  5 13:29:22 2014 
//

#include "exceptions/StartException.hh"

StartException::StartException(const char* name) :
  ZappyException(name)
{
}

StartException::~StartException() throw()
{
}
