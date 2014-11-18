//
// ConfigsException.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:04:58 2014 
// Last Update Tue Nov 18 10:28:54 2014 
//

#include "exceptions/ConfigsException.hh"

ConfigsException::ConfigsException(const char* name) :
  ZappyException(name)
{
}

ConfigsException::~ConfigsException() throw()
{
}
