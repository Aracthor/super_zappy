//
// SyscallException.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:34:34 2014 
// Last Update Sun Oct 12 06:36:56 2014 
//

#include "exceptions/SyscallException.hh"

#include <cerrno>
#include <cstring>

SyscallException::SyscallException(const char* message) :
  ZappyException(message)
{
  m_message += strerror(errno);
}

SyscallException::~SyscallException() throw()
{
}
