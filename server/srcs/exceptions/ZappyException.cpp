//
// ZappyException.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:03:46 2014 
// Last Update Sun Oct 12 06:04:48 2014 
//

#include "exceptions/ZappyException.hh"

ZappyException::ZappyException(const char* message) :
  m_message(message)
{
}

ZappyException::~ZappyException() throw()
{
}


const char*
ZappyException::what() const throw()
{
  return (m_message.c_str());
}
