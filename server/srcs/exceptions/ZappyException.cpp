//
// ZappyException.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:03:46 2014 
// Last Update Wed Dec 17 12:23:08 2014 
//

#include "exceptions/ZappyException.hh"

ZappyException::ZappyException(const char* message) :
  m_message(message)
{
}

ZappyException::ZappyException(const char* message, const char* arg) :
  m_message(std::string(message) + " with arg " + arg)
{
}

ZappyException::ZappyException(const std::string& message) :
  m_message(message)
{
}

ZappyException::ZappyException(const std::string& message, const char* arg) :
  m_message(message + " with arg " + arg)
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
