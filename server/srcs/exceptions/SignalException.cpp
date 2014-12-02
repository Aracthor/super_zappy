//
// SignalException.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 21 12:24:49 2014 
// Last Update Fri Nov 21 12:27:42 2014 
//

#include "exceptions/SignalException.hh"

#include <cstring>

SignalException::SignalException(int signum) :
  ZappyException(strsignal(signum))
{
}

SignalException::~SignalException() throw()
{
}
