//
// StandartLog.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 16:03:09 2014 
// Last Update Thu Nov 20 10:51:17 2014 
//

#include "debug/LogManager.hh"
#include "debug/StandartLog.hh"

StandartLog::StandartLog(const char* name, FILE* stream, StandartLog::EColor color, bool bold, bool active) :
  Log(name, color, bold, active),
  m_stream(stream)
{
}

StandartLog::~StandartLog()
{
}


void
StandartLog::print(const char* message, va_list list)
{
  char		buffer[0x100];

  if (m_active)
    {
      vsprintf(buffer, message, list);
      LogManagerSingleton::access()->addToFile(buffer);

      fprintf(m_stream, "\033[0%d;3%dm", m_bold, m_color);
      fputs(buffer, m_stream);
      fputs("\033[0m\n", m_stream);
    }
}
