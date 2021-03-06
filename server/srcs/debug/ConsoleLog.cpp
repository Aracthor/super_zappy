//
// ConsoleLog.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 16:30:20 2014 
// Last Update Thu Nov 20 11:33:35 2014 
//

#include "debug/ConsoleLog.hh"
#include "debug/LogManager.hh"

#include <cstdio>

ConsoleLog::ConsoleLog(const char* name, EColor color, bool bold, bool active) :
  Log(name, color, bold, active)
{
}

ConsoleLog::~ConsoleLog()
{
}


void
ConsoleLog::addToLogs(const char* data, unsigned int size)
{
  LogManager::ConsoleBuffer*	buffer;

  buffer = LogManagerSingleton::access()->getBuffer();
  if (buffer->getRemainingSize() > 2)
    {
      sprintf(buffer->getEnd(), "%d%d", m_bold, m_color);
      buffer->addToSize(2);
    }
  size = MIN(buffer->getRemainingSize(), size);
  buffer->pushBack(data, size);
  if (buffer->getRemainingSize() > 0)
    buffer->pushBack('\n');
}

void
ConsoleLog::print(const char* message, va_list list)
{
  unsigned int			size;
  char				data[0x100];

  if (m_active)
    {
      size = vsprintf(data, message, list);

      LogManagerSingleton::access()->addToFile(data);
      this->addToLogs(data, size);
    }
}
