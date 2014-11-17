//
// LogThread.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 18:03:27 2014 
// Last Update Mon Nov 17 08:51:04 2014 
//

#include "core/LogThread.hh"
#include "debug/LogManager.hh"

LogThread::LogThread() :
  AZappyThread("Logs")
{
}

LogThread::~LogThread()
{
}


bool
LogThread::loopCycle()
{
  return (true);
}
