//
// LogThread.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 19 14:20:13 2014 
// Last Update Wed Nov 19 14:44:07 2014 
//

#include "core/ControlPanel.hh"
#include "core/LogThread.hh"

#include <unistd.h>

LogThread::LogThread(ControlPanel* controlPanel) :
  AZappyThread("Logs reader"),
  m_controlPanel(controlPanel)
{
}

LogThread::~LogThread()
{
}


bool
LogThread::loopCycle()
{
  long	timeToWait;

  m_clock.update();
  m_controlPanel->update();
  m_clock.update();

  timeToWait = 1000000 / CONSOLE_FRAMERATE - m_clock.getElapsedTime();
  if (timeToWait > 0)
    usleep(timeToWait);

  return (true);
}
