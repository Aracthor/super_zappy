//
// LogParameter.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov 18 10:18:10 2014 
// Last Update Tue Nov 18 11:01:58 2014 
//

#include "debug/LogManager.hh"
#include "debug/LogParameter.hh"

LogParameter::LogParameter()
{
  this->addCommand("active",	&LogParameter::active);
  this->addCommand("disactive",	&LogParameter::disactive);
}

LogParameter::~LogParameter()
{
}


void
LogParameter::active(const char* params __attribute__ ((unused)))
{
  m_workingLog->setActive(true);
}

void
LogParameter::disactive(const char* params __attribute__ ((unused)))
{
  m_workingLog->setActive(false);
}


void
LogParameter::executeLogCommand(const char* command, const char* logName, const char* params)
{
  const char*	ptr;
  char		buffer[0x100];
  unsigned int	size;

  ptr = strchr(logName, ' ');
  size = (ptr - logName);
  strncpy(buffer, logName, size);
  buffer[size + 1] = '\0';

  m_workingLog = LogManagerSingleton::access()->getLogFromName(buffer);
  if (m_workingLog == NULL)
    LogManagerSingleton::access()->error->print("Unknow log %s", buffer);
  else
    this->executeCommand(command, params);
}
