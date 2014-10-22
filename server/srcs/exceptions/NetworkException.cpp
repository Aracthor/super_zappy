//
// NetworkException.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:04:58 2014 
// Last Update Sun Oct 12 08:05:14 2014 
//

#include "exceptions/NetworkException.hh"

NetworkException::NetworkException(const char* name) :
  SyscallException(name)
{
}

NetworkException::~NetworkException() throw()
{
}
