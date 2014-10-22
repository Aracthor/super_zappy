//
// ThreadingException.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 10:38:15 2014 
// Last Update Sun Oct 12 10:40:22 2014 
//

#include "exceptions/ThreadingException.hh"

#include <cstring>

ThreadingException::ThreadingException(const char* message, int error) :
  ZappyException(message)
{
  m_message += strerror(error);
}

ThreadingException::~ThreadingException() throw()
{
}
