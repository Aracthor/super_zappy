//
// Clock.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sat Nov  8 20:51:53 2014 
// Last Update Sat Nov  8 21:46:37 2014 
//

#include "abstractions/Clock.hh"
#include "exceptions/SyscallException.hh"

#include <cstring>

Clock::Clock() :
  m_elapsedTime()
{
  memset(&m_lastTime, 0, sizeof(m_lastTime));
  this->update();
}

Clock::~Clock()
{
}


#include <cstdio> // DEBUG
void
Clock::update()
{
  struct timeval	timeofday;

  if (gettimeofday(&timeofday, NULL) != 0)
    throw SyscallException("Clock cannot get time");

  m_elapsedTime = ((timeofday.tv_sec - m_lastTime.tv_sec) * 1000000 +
		   timeofday.tv_usec - m_lastTime.tv_usec);
  m_lastTime = timeofday;
}
